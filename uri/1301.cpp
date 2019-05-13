#include <bits/stdc++.h>
#define MAXN 1000100

using namespace std;

int bit[3 * MAXN];
int bit0[3 * MAXN];

// Bits para tratar o zero
void update0(int index, int value) {
  for (int i = index; i <= MAXN; i += (i & -i)) {
    bit0[i] += value;
  }
}

int query0(int position) {
  int ans = 0;
  for (int i = position; i > 0; i -= (i & -i)) {
    ans += bit0[i];
  }
  return ans;
}

// Bit normal

void update(int index, int value) {
  for (int i = index; i <= MAXN; i += (i & -i)) bit[i] += value;
}

int query(int position) {
  int ans = 0;
  for (int i = position; i > 0; i -= (i & -i)) ans += bit[i];
  return ans;
}

int main() {

  int n, k, i, j;
  int elements[MAXN];
  char op;

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> elements[i]; 
    if (elements[i] == 0) {
      update0(i, 1);
    } else if (elements[i] > 0) {
      update(i, 1);
    }
  }

  while(k--) {
    cin >> op >> i >> j;
    if (op == 'C') { // Change a sequence's value
      if (j == 0) {
        update0(i, 1);
        update(i, 0);
      } else if (j < 0) {
        update0(i, 0);
        update(i, 0);
      } else {
        update0(i, 0);
        update(i, 1);
      }
      
    } else { // Calculate the product of a sub-sequence
      int containsZero = query0(j) - query0(i - 1);
      // cout << "bla: " <<  containsZero << endl;
      if (containsZero > 0 && false) {
        cout << "0";
      } else {
        int qtdPositives = query(j) - query(i - 1);
        bool ans = (((j - i - 1) - qtdPositives) % 2 == 0) ? true : false;
        cout << (ans ? "+": "-");
      }
    }
  }

  cout << endl;

  return 0;
}