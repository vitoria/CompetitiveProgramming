#include <bits/stdc++.h>
#define MAXN 10001

using namespace std;

int n, m, k;
char maze[MAXN][MAXN];
bool visited[MAXN][MAXN];
int qtd_visited;
int qtd_empty = 0;

void dfs(int x, int y) {

  if (qtd_visited < qtd_empty - k) {
    visited[x][y] = true;
    qtd_visited++;
    if (x + 1 < n && !visited[x + 1][y] && maze[x + 1][y] == '.') dfs(x + 1, y);
    if (x - 1 > -1 && !visited[x - 1][y] && maze[x - 1][y] == '.') dfs(x - 1, y);
    if (y + 1 < m && !visited[x][y + 1] && maze[x][y + 1] == '.') dfs(x, y + 1);
    if (y - 1 > -1 && !visited[x][y - 1] && maze[x][y - 1] == '.') dfs(x, y - 1);
  }
}


int main() {
  int x, y;

  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> maze[i][j];
      if (maze[i][j] == '.') {
        qtd_empty++;
        x = i; y = j;
      }
    }
  }

  dfs(x, y);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (maze[i][j] == '.' && !visited[i][j]) cout << "X";
      else cout << maze[i][j];
    }
    cout << endl;
  }
  
  return 0;
}