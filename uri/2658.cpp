#include <bits/stdc++.h>
#define MAXN (int)1e5 + 3
#define ll long long int
#define pll pair<ll, ll>
#define NEUTRO_ELEMENT {0, 0}

using namespace std;

pll segtree[MAXN * 4];
ll lazy[MAXN * 4];

void propagate(int id, int l, int r) {
  if (l != r) {
    lazy[2 * id] += lazy[id];
    lazy[2 * id + 1] += lazy[id];
  }
  segtree[id].first += lazy[id];
  lazy[id] = 0;
}

pll seg_operation(pll a, pll b) {
  if (a.first == b.first) return {a.first, a.second + b.second};
  else if (a.second == b.second) return {max(a.first, b.first), a.second};
  else if (a.second < b.second) return b;
  return a;
}

void build(int id, int l, int r) {
  if (l == r) {
    segtree[id].first = 1;
    segtree[id].second = 1;
  } else {
    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    segtree[id] = seg_operation(segtree[2 * id], segtree[2 * id + 1]);
  }
}

pll query(int id, int l, int r, int x, int y) {
  propagate(id, l, r);
  if (x <= l && r <= y)
    return segtree[id];
  else if (y < l || r < x)
    return NEUTRO_ELEMENT;
  int m = (l + r) / 2;
  return seg_operation(query(2 * id, l, m, x, y), query(2 * id + 1, m + 1, r, x, y));
}

void update(int id, int l, int r, int x, int y, int v) {
  propagate(id, l, r);
  if (x <= l && r <= y) {
    lazy[id] += v;
    propagate(id, l, r);
  } else if (!(x > r || y < l)) {
    int m = (r + l) / 2;
    propagate(id, l, r);
    update(2 * id, l, m, x, y, v);
    update(2 * id + 1, m + 1, r, x, y, v);
    segtree[id] = seg_operation(segtree[2 * id], segtree[2 * id + 1]);
  }
  propagate(id, l, r);
}

void waza() {
  for (int i = 1; i < 12; i++) {
      cout << "(" << segtree[i].first << ", " << segtree[i].second << ", " << lazy[i] << "), ";
    }
    cout << endl;
}

int main() {

  int n, q, x, y;

  cin >> n >> q;

  build(1, 1, n);

  // for (int i = 0; i < q; i++) {
  //   cin >> l >> r;
  //   pll ans = query(1, 1, n, l, r);
  //   cout << ans.first << ", " << ans.second << endl;;
  // }

  // cout << endl;

  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    int a = query(1, 1, n, x + 1, y + 1).first;
    cout << a << endl;
    update(1, 1, n, x + 1, y + 1, a);
    waza();
  }

  cout << endl << endl;
  for (int i = 1; i <= n; i++) {
    cout << query(1, 1, n, i, i).first << ", ";
  }
  cout << endl;

  return 0;
}