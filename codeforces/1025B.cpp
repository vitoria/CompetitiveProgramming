#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define MAXN 2000100

using namespace std;

pll arr[MAXN];
ll divisors[MAXN];

int main() {

  int n, index = 0;
  ll ans = 0;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    divisors[i] = arr[i].first * (arr[i].second / __gcd(arr[i].first, arr[i].second));
  }

  ans = __gcd(divisors[0], divisors[1]);
  for (int i = 2; i < n; i++) {
    ans = __gcd(ans, divisors[i]);
  }

  for(int i = 0; i < n; i++){
    if(__gcd(arr[i].first, ans) != 1) ans = __gcd(arr[i].first, ans);
    if(__gcd(arr[i].second, ans) != 1) ans = __gcd(arr[i].second, ans);
  }

  printf("%lld\n", ans == 1 ? -1 : ans);

  return 0;
}