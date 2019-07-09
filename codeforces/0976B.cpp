#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	
  int n, m;
  int x, y;
	ll k;

	cin >> n >> m >> k;
	
	if (k < n) {
		cout << (k + 1) << " " << 1 << endl;
	} else if (k == n) {
		cout << n << " " << 2 << endl;
	} else {
    k -= n;
    m -= 1;
    x = n - (k/m);
    y = k % m;
    
    cout << x << " " << ((x % 2 == 0) ? (y + 2) : (m - y + 1)) << endl;
  }

  return 0;
}