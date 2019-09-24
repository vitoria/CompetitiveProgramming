#include <bits/stdc++.h>
#define MAXN (int)1e5 + 1
#define INF 1e5

using namespace std;

vector<int> graph[MAXN];

using namespace std;

bool visited[MAXN];

int sum;
bool achou_k7;

int dfs(int parent, int node, int dist, int acc) {
  visited[node] = true;
  int ans = -1;
  for (int i = 0; i < graph[node].size(); i++) {
    if (!visited[graph[node][i]]) {
      ans = max(dfs(node, graph[node][i], dist + 1, graph[node].size()), ans);
    } else if (dist == 1 && graph[node][i] != parent) {
      achou_k7 = true;
      return (acc + graph[graph[node][i]].size() + graph[node].size()) - 6;
    }
  }
  return ans;
}

int main() {

  int n, m, a, b;
  int ans = 0;

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 1; i <= n && ans > -1; i++) {
    memset(visited, false, sizeof(visited));
    // int bla = dfs(i, 0, 0);
    ans = max(ans, dfs(i, i, 0, 0));
  }
  if (achou_k7) {

  cout << ans << endl;
  } else cout << -1 << endl;

  return 0;
}