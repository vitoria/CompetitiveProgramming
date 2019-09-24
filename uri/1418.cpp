#include <bits/stdc++.h>
#define MAXN (int)1e5 + 10

using namespace std;

vector<int> graph[MAXN];
int n, x;
float t;

int dfs(int node) {
  vector<int> children;
  int ans = 0;
  for (int i = 0; i < graph[node].size(); i++) {
    children.push_back(dfs(graph[node][i]));
  }
  sort(children.begin(), children.end());
  for (int i = 0; i < ceil(children.size() * t); i++) {
    ans += children[i];
  }
  return (ans == 0) ? 1 : ans;
}

int main() {

  while(cin >> n >> t && t != 0 && n != 0) {
    for (int i = 0; i < MAXN; i++) graph[i].clear();
    t /= 100.0;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      graph[x].push_back(i); 
    }

    cout << dfs(0) << endl;
  }
  

  return 0;
}