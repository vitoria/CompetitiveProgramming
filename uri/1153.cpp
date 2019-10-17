#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;
  long long ans = 1;

  cin >> n;

  for (; n > 1; n--) {
    ans *= n;
  }

  cout << ans << endl;

  return 0;
}