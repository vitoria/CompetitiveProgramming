#include <bits/stdc++.h>
#define ll long long int
#define MAXN 101000

using namespace std;

ll MOD = 1e9 + 7;
ll dp[MAXN][100];
ll t, m, n;

ll sum(ll a, ll b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}

ll ans = 0;

ll waza(ll current, ll time) {
  if (current != -1 && dp[current][time] != -1) return dp[current][time];
  if (current == -1) {
    ll acc = 0;
    for (int i = m; i <= n; i++) {
      acc = sum(acc, waza(i, time + 1));
    }
    return acc;
  }
  if (current < m || current > n) return 0;
  if (time == t) return 1;
  dp[current][time] = sum(sum(0, waza(current - 1, time + 1)), waza(current + 1, time + 1));
  return dp[current][time];

}

int main() {

  cin >> t >> m >> n;

  memset(dp, -1, sizeof(dp));

  // for (int i = 0; i < 6; i++) {
  //   cout << dp[0][i] << ", ";
  // }

  // cout << endl;

  ans = waza(-1, 0);

  cout << ans << endl;

  // cout << test() << endl;

  return 0;
}