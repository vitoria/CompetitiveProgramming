#include <bits/stdc++.h>
#define MAXN 110

using namespace std;

int land[MAXN][MAXN][MAXN + 1];
int n, r, c, k;

int isEnimeOf(int i) {
  return (i + n - 1) % n;
}

void adj(int k, int i, int j) {
  int z = isEnimeOf(land[k][i][j]);
  if (i > 0 && land[k][i - 1][j] == z ||
    i < (r - 1) && land[k][i + 1][j] == z ||
    j > 0 && land[k][i][j - 1] == z ||
    j < (c - 1) && land[k][i][j + 1] == z
  ) {
    land[k - 1][i][j] = z;
  } else {
    land[k - 1][i][j] = land[k][i][j];
  }
}

int main() {

  while (cin >> n >> r >> c >> k && k != 0) {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cin >> land[k][i][j];
      }
    }

    for (; k; k--) {
      for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
          adj(k, i, j);
        }
      }
    }

    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        cout << land[0][i][j] << ((j < c - 1) ? " " : "");
      }
      cout << endl;
    }
  }

  return 0;
}