#include <bits/stdc++.h>

using namespace std;

#define MAXL 21
#define MAXN 2000100
#define ll long long

int sparseTable[MAXL][MAXN], elements[MAXN], n;
int ans[MAXN];

int log(int n) {
    return __builtin_clz(1) - __builtin_clz(n);
}

void build() {
	for(int i = 0; i < n; i++) sparseTable[0][i] = elements[i];

	for(int j = 1; j < MAXL; j++) {
		for(int i = 0; (i + (1 << (j-1))) < n; i++) {
			sparseTable[j][i] = min(sparseTable[j-1][i], sparseTable[j-1][i + (1 << (j-1))]);
		}
	}
}

int query(int l, int r) {
    int lg = log(r - l + 1);
	return min(sparseTable[lg][l], sparseTable[lg][r - (1 << lg) + 1]);
}

int binary_left(int l, int r, int pos, int value) {
  if (l <= r) {
    int middle = (l + r) / 2;
    ll result = query(middle, pos);
    if (result == value) {
       return min(middle, binary_left(l, middle - 1, pos, value));
    } else {
       return binary_left(middle + 1, r, pos, value);
    }
  }
  return pos;
}

int binary_right(int l, int r, int pos, int value) {
  if (l <= r) {
    int middle = (l + r) / 2;
    ll result = query(pos, middle);
    if (result == value) {
       return max(middle, binary_right(middle + 1, r, pos, value));
    } else {
       return binary_right(l, middle - 1, pos, value);
    }
  }
  return pos;
}

int main() {
  int left, right, pos, current;

  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> elements[i];
  }

  build();

  for (int i = 0; i < n; i++) {
    left = binary_left(0, i, i, elements[i]);
    right = binary_right(i, n-1, i, elements[i]);
    pos = right - left;
    ans[pos] = max(ans[pos], elements[i]);
  }  

  current = ans[n - 1];
  for (int i = n-2; i >= 0; i--) {
    ans[i] = max(ans[i], current);
    current = max(ans[i], current);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i + 1 == n];
  } 

  return 0;
}