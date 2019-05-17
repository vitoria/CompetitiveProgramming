#include <bits/stdc++.h>
#define MAXN 100010
#define NEUTRO_ELEMENT 1

using namespace std;

int segTree[4 * MAXN];
int elements [MAXN];

int n, k, x, y;
char op;
string ans;

int seg_operation(int a, int b) {
  return a * b;
}

void build(int id, int left, int right) {
  if (left == right) {
    segTree[id] = elements[left];
  } else {
    int middle = (left + right) / 2;
    build(2 * id, left, middle);
    build(2 * id + 1, middle + 1, right);
    segTree[id] = seg_operation(segTree[2 * id], segTree[2 * id + 1]);
  }
}

int query(int id, int left, int right, int x, int y) {
  if (x <= left && right <= y) {
    return segTree[id];
  } else if (y < left || right < x) {
    return NEUTRO_ELEMENT;
  } else {
    int middle = (left + right) / 2;
    return seg_operation(
      query(2 * id, left, middle, x, y),
      query(2 * id + 1, middle + 1, right, x, y)
    );
  }
}

void update(int id, int left, int right, int position, int value) {
  if (left == right) {
    segTree[id] = value;
  } else {
    int middle = (left + right) / 2;
    if (position > middle) {
      update(2 * id + 1, middle + 1, right, position, value);
    } else {
      update(2 * id, left, middle, position, value);
    }
    segTree[id] = seg_operation(segTree[2 * id], segTree[2 * id + 1]);
  }
} 

int getSignal(int n) {
  return (n == 0) ? 0 : ((n < 0) ? -1 : 1);
}

int solve() {
  ans = "";
  memset(elements, 0, sizeof(elements));
  memset(segTree, 0, sizeof(segTree));

  for (int i = 1; i <= n; i++) {
    cin >> elements[i];
    elements[i] = getSignal(elements[i]);
  }

  build(1, 1, n);

  while (k--) {
    cin >> op >> x >> y;
    if (op == 'C') {
      y = getSignal(y);
      update(1, 1, n, x, y);
    } else {
      int result = query(1, 1, n, x, y);
      ans += ((result == 0) ? "0" : ((result == 1) ? "+" : "-"));
    }
  }
  cout << ans << endl;
}

int main() {
 
  while (cin >> n >> k) {
    solve();
  }

  return 0;
}