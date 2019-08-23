#include <bits/stdc++.h>
#define MAXN (int) 1e5 + 1

using namespace std;

typedef struct {
  int next;
  int jumps;
} node;

node holes[MAXN];

int main() {

  for (int i = 1; i < MAXN; i++) {
    holes[i] = { 0, 1 };
  }

  int n, power, q, op;

  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    cin >> power;
    holes[i].next = i + power;
    if (i + power > n) holes[i].next = 0;
  }

  int hole, x ,y;

  while (cin >> op) {
    if (op == 1) {
      cin >> hole;
      int ans = 1;
      while (holes[hole].next) {
        ans++;
        hole = holes[hole].next;
      }
      cout << hole << " " << ans << endl;
    } else {
      cin >> x >> y;
      holes[x].next = x + y;
      if (holes[x].next > n) holes[x].next = 0;
    }
  }

  return 0;
}