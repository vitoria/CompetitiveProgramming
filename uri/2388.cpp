#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x, y;
  long long ans = 0;

  cin >> n;

  for (; n; n--) {
    cin >> x >> y;
    ans += x * y;
  } 

  cout << ans << endl;

  return 0;
}