#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
  ll a, b, ans = 0;

  cin >> a >> b;

  if (a == b) cout << "infinity\n";
  else if (a < b) cout << "0\n";
  else {
    ll diff = a - b;
    for (int i = 1; i <= (int) sqrt(diff); i++) {
      if (diff % i == 0) {
        if (i > b) ans++;
        if((diff/i) > b && (diff/i) != i) ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}