#include <bits/stdc++.h>
#define MAXN (int) 1e5 + 10
#define ll long long

using namespace std;

vector<ll> graph[MAXN];
bool dude[MAXN];
ll cost[MAXN];

ll ans = 0;
ll max_cost = 0;

ll dfs(ll node, ll path_cost) {
  ll acc = 0;
  for (int i = 0; i < graph[node].size(); i++) {
    acc += dfs(graph[node][i], path_cost + cost[node]);
  }

  if (acc == 0 && !dude[node]) return 0; 

  if (dude[node]) {
    max_cost = max(max_cost, cost[node] + path_cost);
  }

  return cost[node] + acc;

}

int main() {

  int n, qtd;;
  int x, y, z;

  while(cin >> n) {
    cin >> qtd;

    cost[1] = 0;

    for (int i = 0; i < n - 1; i++) {
      cin >> x >> y >> z;
      graph[x].push_back(y);
      cost[y] = z;
    }


    for (int i = 0; i < qtd; i++) {
      cin >> x;
      dude[x] = true;
    }

    ans = dfs(1, 0);

    cout << ans - max_cost << endl;

    max_cost = 0;
    for (int i = 0; i < MAXN; i++) {
      dude[i] = false;
      graph[i].clear();
    }
  }

  return 0;
}