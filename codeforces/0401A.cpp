#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {

  int n, x, aux;
  ll sum = 0;
  int ans = 0;

  cin >> n >> x;

  for (int i = 0; i < n; i++) {
    cin >> aux;
    sum += aux;
  }


  sum = abs(sum);
  while (x > 0 && sum > 0) {
    ans += sum / x;
    sum = sum % x;
    x--;
  }

  cout << ans << endl;

  return 0;
}