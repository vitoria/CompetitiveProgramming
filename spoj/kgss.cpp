#include <bits/stdc++.h>
#define MAXN 2000100

using namespace std;

int bit[4 * MAXN];

void update(int index, int value) {
  for (int i = index; i <= MAXN; i += (i & -i)) {
    bit[i] += value;
  }
}

int query(int position) {
  int ans = 0;

  for (int i = position; i > 0; i -= (i & -i)) {
    ans += bit[i];
  }

  return ans;
}

int main() {
  int n, m, i, j;
  int elements[MAXN];
  char op;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> elements[i];
    update(i + 1, elements[i]);
  }

  cin >> m;

  while(m--) {
    cin >> op >> i >> j;
    if (op == 'U') {
      update(i, j);
    } else {
      cout << "Q\n";
    }
  }


  return 0;
}