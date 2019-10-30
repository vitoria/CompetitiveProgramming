#include <bits/stdc++.h>
#define MAXN (ll)1e6
#define ll long long

using namespace std;

ll acc[MAXN];

int main() {

  ll j, r, x;
  ll ans = 0;
  ll maxn = -1;

  cin >> j >> r;

  for (ll i = 0; i < (j * r); i++) {
    cin >> x;
    acc[i % j] += x;
  }

  for (int i = 0; i < (j * r); i++) {
    if (acc[i] >= maxn) {
      maxn = acc[i];
      ans = i;
    }
  }

  cout << ans + 1 << endl;

  return 0;
}