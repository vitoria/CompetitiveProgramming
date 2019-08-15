#include <bits/stdc++.h>
#define MAXN 200100

using namespace std;

int segA[MAXN * 4];
int segB[MAXN * 4];
int n, k, a, b, q, op;

void update(int id, int l, int r, int pos, int value) {
  if (l == r) {
    segA[id] = min(a, value); segB[id] = min(b, value);
  } else {
    int m = (l + r) / 2;
    if (pos < m) {
      update(2 * id, l, m, pos, value);
      segA[id] = segA[2 * id] + segA[2 * id + 1];
      segB[id] = segB[2 * id] + segB[2 * id + 1];
    } else {
      update(2 * id + 1, m + 1, r, pos, value);
      segA[id] = segA[2 * id] + segA[2 * id + 1];
      segB[id] = segB[2 * id] + segB[2 * id + 1];
    }
  }
}

int query(int id, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
      return segB[id];
    } else if (r < x || y < l) {
      return segA[id];
    } else {
      int m = (l + r) / 2;
      return query(2 * id, l, m, x, y) + query(2 * id + 1, m + 1, r, x, y);
    }
}

int main() {

  int v, m;

  cin >> n >> k >> a >> b >> q;

  for ( ; q; q--) {
    cin >> op;
    if (op == 1) {
      cin >> v >> m;
      update(1, 1, n, v, m);
    } else {
      cin >> v;
      cout << query(1, 1, n, v - 1, v + k) << endl;
    }
  }

  return 0;
}