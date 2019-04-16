#include <bits/stdc++.h>

using namespace std;

#define MAXL 21
#define MAXN 1000100
#define ll long long

ll sparseTable[MAXL][MAXN], elements[MAXN], n;
ll differences[MAXN];

int log(int n) {
    return __builtin_clz(1) - __builtin_clz(n);
}

void build() {
	for(int i = 0; i < n; i++) sparseTable[0][i] = differences[i];

	for(int j = 1; j <= 20; j++) {
		for(int i = 0; (i + (1 << (j-1))) < n; i++) {
			sparseTable[j][i] = max(sparseTable[j-1][i], sparseTable[j-1][i + (1 << (j-1))]);
		}
	}
}

int query(int l, int r) {
    int lg = log(r - l + 1);
	return max(sparseTable[lg][l], sparseTable[lg][r - (1 << lg) + 1]);
}

int binary_search(int l, int r, int t_pos, int value) {
//  cout << l << ", " << r << endl;
  if (l >= 0 && r <= t_pos && l <= r && r >= 0 && t_pos >= 0) {
    int middle = (l + r) / 2;
    int result = query(middle, t_pos);
  //  cout << middle << " " << t_pos << " " << result << " *" << endl;
    if (result > value) {
      return binary_search(middle + 1, r, t_pos, value);
    } else {
      if (middle > 0 && differences[middle - 1] > value) return middle + 1;
      return binary_search(l, middle - 1, t_pos, value);
    }
  }
  if (r >= t_pos) return t_pos + 2;
  return 1;
}

int main() {
  memset(sparseTable, -1, sizeof sparseTable);
  ll m, t, d, k, ans;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> elements[i];
  }

  for (int i = 0; i < (n - 1); i++) {
    differences[i] = elements[i + 1] - elements[i];
  }
  differences[n - 1] = -1;

  //cout << endl;
  build();

  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> t >> d;
    // cout << "Test #" << i + 1 << endl;
    // cout << "t: " << t << "   ... d: " << d << endl;
    k = upper_bound(elements, elements + n, t) - elements;
    //cout << k << endl;
    ans = binary_search(0, k - 2,  k - 2, d);
    if (k <= 1) ans = 1;
    if (k == 2) ans = differences[0] <= d ? 1 : 2;
    cout << ans << endl;
  }

  return 0;
}