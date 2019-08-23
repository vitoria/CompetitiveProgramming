#include <bits/stdc++.h>
#include MAXN 30

using namespace std;

int graph[MAXN][MAXN];
int visited[MAXN];


void dfs(int node, int cost) {
  for (int i = 0; i < MAXN; i++) {

  }
}

int main() {

  string s, t;
  char x, y;
  int n, z;
  int ans = 0;

  cin >> s >> t >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    x -= 'a'; y -= 'a';
    if (graph[x][y] == 0) {
      graph[x][y] = z + 1;
    } else {
      graph[x][y] = min(graph[x][y], z + 1);
    }
  }

  dfs(0, 0);



  if (s.size() != t.size()) {
    ans = -1;
  } else {
    int costA, costB;
    for (int i = 0; i < s.size() && ans != -1; i++) {
      if (s[i] != t[i]) {
        costA = changes[s[i]][t[i]];
        costB = changes[t[i]][s[i]];
        if (costA != 0 && costB != 0) {
          if (min(costA, costB) == costA) {
            s[i] = t[i];
            ans += costA - 1;
          } else {
            ans += costB - 1;
          }
        } else if (costA != 0 || costB != 0) {
          if (max(costA, costB) == costA) {
            s[i] = t[i];
            ans += costA - 1;
          } else {
            ans += costB - 1;
          }
        } else {
          ans = -1;
        }
      }
    }
  }

  cout << ans << endl;
  if (ans != -1) cout << s << endl;

  return 0;
}