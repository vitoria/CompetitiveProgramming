#include <bits/stdc++.h>

using namespace std;

bool board[10][10];

bool solve(int x, int y) {
  if (x == 4 and y == 4) return true;
  if (x > 4 or y > 4 or x < 0 or y < 0 or board[x][y]) return false;

  board[x][y] = 1;

  return solve(x-1, y) or solve(x, y-1) or solve(x+1, y) or solve(x, y+1);
}

int main() {
  int n;

  cin >> n; 

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> board[i][j];
      }
    }

    cout << (solve(0, 0) ? "COPS" : "ROBBERS") << endl;

    memset(board, false, sizeof(board));
  };

  return 0;
}