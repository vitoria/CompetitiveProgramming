#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
#define MAXL 20

using namespace std;

ll sparseTable[MAXN][MAXL];
ll elements[MAXN];
ll n;

int log(ll n) {
  return __builtin_clz(1) - __builtin_clz(n);
}

void build() {
  for (int i = 0; i < n; i++) {
    sparseTable[i][0] = elements[i];
  }

  for (int j = 1; j <= log(n); j++) {
    for (int i = 0; (i + (1 << (j - 1))) < n; i++) {
      sparseTable[i][j] = min(
        sparseTable[i][j - 1],
        sparseTable[i + (1 << (j - 1))][j - 1]);
      }
  }
}

ll query(int l, int r) {
  int lg = log(r - l + 1);
  return min(
    sparseTable[l][lg],
    sparseTable[r - (1 << lg) + 1][lg]
  );
}

int main() {
  cin >> n;

  int l, r;

  for (int i = 0; i < n; i++) {
    cin >> elements[i];
  }

  build();

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> l >> r;
    cout << query(l, r) << endl;
  }

  return 0;
}