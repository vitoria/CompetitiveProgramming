#include <bits/stdc++.h>
#define MAXN 1000010

using namespace std;

typedef struct {
  int open;
  int ok;
  int close;
} node;

node segTree[4*MAXN];
string elements;

void build(int id, int l, int r) {
  if (l == r) {
    if (elements[l] == '(') {
      segTree[id].open = 1;
      segTree[id].ok = 0;
      segTree[id].close = 0;
    } else {
      segTree[id].open = 0;
      segTree[id].ok = 0;
      segTree[id].close = 1;
    }
  } else {
    int middle = (l + r) / 2;
    int child_left = 2 * id;
    int child_right = 2 * id + 1;
    build(child_left, l, middle);
    build(child_right, middle + 1, r);
    segTree[id].ok = segTree[child_left].ok
      + segTree[child_right].ok
      + min(segTree[child_left].open, segTree[child_right].close);
    segTree[id].open = max(0, segTree[child_left].open - segTree[child_right].close)
      + segTree[child_right].open;
    segTree[id].close = max(0, segTree[child_right].close - segTree[child_left].open)
      + segTree[child_left].close;
  }
}

node query(int id, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return segTree[id];
  } else if (y < l || r < x) {
    return {0, 0, 0};
  } else {
    int middle = (r + l) / 2;
    node left = query(2 * id, l, middle, x, y);
    node right = query(2 * id + 1, middle + 1, r, x, y);
    return {
      max(0, left.open - right.close) + right.open,
      left.ok + right.ok + min(left.open, right.close),
      max(0, right.close - left.open) + left.close
    };
  }
}

int main () {
  int m, l, r;
  cin >> elements;

  build(1, 0, elements.size() - 1);

  // for (int i = 0; i < elements.size(); i++) {
  //   cout << segTree[i].ok << "\n";
  // }

  cin >> m;
  while (m--) {
    cin >> l >> r;
    cout << 2 * query(1, 0, elements.size() - 1, l-1, r-1).ok << endl;
  }
  return 0;
}