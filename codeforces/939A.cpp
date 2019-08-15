#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

vector<int> graph[MAXN];
bool visited[MAXN];

bool dfs(int v, int jumps, int root) {
  // cout << "v: " << v << endl;
  // cout << "jumps: " << jumps << endl;
  // cout << "root: " << root << endl << endl;
  visited[v] = true;
  for (int i = 0; i < graph[v].size(); i++) {
    if (jumps == 2) {
      if (root == graph[v][i]) return true;
    } else {
      if (jumps > 3) return false;
      if (!visited[graph[v][i]]) {
        return dfs(graph[v][i], jumps + 1, root);
      }
    }
  }
  return false;
}

int main() {

  int n, a;
  bool containsTri = false;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a;
    graph[i].push_back(a - 1);
  }

  for (int i = 0; i < n && !containsTri; i++) {
    memset(visited, 0, MAXN);
    containsTri = dfs(i, 0, i);
  }
  
  cout << (containsTri ? "YES" : "NO") << endl;

  return 0;
}