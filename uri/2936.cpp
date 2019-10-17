#include <bits/stdc++.h>

using namespace std;

int main() {

  int cost[] = {300, 1500, 600, 1000, 150};
  long long a, ans = 0;

  for (int i = 0; i < 5; i++) {
    cin >> a;
    ans += a * cost[i];
  }

  cout << ans + 225 << endl;

  return 0;
}