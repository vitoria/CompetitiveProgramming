#include <bits/stdc++.h>
#define MAXN 200010

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
  int n, k;
  int elements[MAXN];
  char op;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> elements[i];
    update(i, elements[i]);
  }

  while(cin >> op >> k) {
    if (op == 'a') { // Abduzir um buggie
      update(k, -elements[k]);
    } else { // Calcular quantas pessoas tem depois do késsimo buggie
      cout << query(k - 1) << endl;
    }
  }

  return 0;
}