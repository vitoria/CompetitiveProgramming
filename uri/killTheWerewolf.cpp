#include <bits/stdc++.h>
#define MAXN (int)52
#define INF 1e9 + 7
// #define pii pair<int, int>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

int main(){
  pii edges[MAXN];
  int n, ans;
  int votes;

  while (cin >> n) {
    ans = 0;
    for (int i = 1; i <= n; i++) {
      cin >> edges[i].first >> edges[i].second;
    }

    for (int i = 1; i <= n; i++) {
      votes = 0;
      Dinic graph = Dinic((2 * n) + 2, 0, (2 * n) + 1);
      for (int j = 1; j <= n; j++) {
        if (i != j && edges[j].first != i && edges[j].second != i) {
          graph.add(0, j, 1);
          graph.add(j, n + edges[j].first, 1);
          graph.add(j, n + edges[j].second, 1);
        } else {
          votes++;
        }
      }
      votes--;
      for (int j = 1; j <= n; j++) {
        if (j == edges[i].first || j == edges[i].second) {
          graph.add(n + j, (2 * n) + 1, votes - 2);
        } else {
          graph.add(n + j, (2 * n) + 1, votes - 1);
        }
      }
      ll others = graph.flow();
      if (others < n - votes - 1) ans++;
      // cout << i << endl;
      // cout << "others: " <<  others << endl;
      // cout << "votes: " << votes << endl;
    }


    cout << ans << endl;
  }


	return 0;
}