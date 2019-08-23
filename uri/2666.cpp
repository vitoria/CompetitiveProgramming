#include <bits/stdc++.h>
#define ll long long
#define MAXN (int)1e5

using namespace std;

ll impost[MAXN];
vector<pair<int, int>> graph[MAXN];
bool visited[MAXN];
ll ans = 0;
int n, x, y, z;
float m;

ll dfs(int node, int dist) {
  visited[node] = true;
  ll acc = 0;
  for (int i = 0; i < graph[node].size(); i++)
    if (!visited[graph[node][i].first])
      acc += dfs(graph[node][i].first, graph[node][i].second);
  acc += impost[node];
  ans += ceil((acc / m)) * dist * 2;
  return acc;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    cin >> impost[i];

  for (int i = 0; i < n - 1; i++) {
    cin >> x >> y >> z;
    graph[x].push_back({y, z});
    graph[y].push_back({x, z});
  }

  dfs(1, 0);

  cout << ans << endl;

  return 0;
}