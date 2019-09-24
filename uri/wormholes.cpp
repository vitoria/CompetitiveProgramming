#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve() {
    vector<int> d(n);
    vector<int> p(n, -1);
    int x;
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] + e.cost < d[e.b]) {
                d[e.b] = d[e.a] + e.cost;
                p[e.b] = e.a;
                x = e.b;
            }
        }
    }

    if (x == -1) {
        cout << "not possible\n";
    } else {
        for (int i = 0; i < n; ++i)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "possible\n";
    }
}

int main() {
  
  int k;
  int x, y, z;

  cin >> k;

  for (; k; k--) {
    cin >> n >> m;
    edges.clear();
    for (int i = 0; i < m; i++) {
      cin >> x >> y >> z;
      edges.push_back({ x, y, z });
    }
    solve();
  }

}