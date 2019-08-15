#include <bits/stdc++.h>
#define ll unsigned long long int
#define ld long double
#define DECIMAL_PART pow(10, 19)
#define MAXA 100000

using namespace std;

ll mod;

pair<ll, ll> exp(ll a, ll c, ll b){
    if(b == 0) return {1, 1};
    if(b%2 == 0){
        pair<ll, ll> r = exp(a, c, b/2);
        ll k = (r.first * r.first) % 10000;
        ll y = (r.second * r.second) % (int)DECIMAL_PART;
        k += (r.second * r.second) / (int)DECIMAL_PART;
        return { k % 10000, y };
    } 
    return ((exp(a, c, b-1)) * (a % mod)) % mod;
}

int main() {

  ll a, b, n, k;
  ld x;

  cin >> a >> b >> n >> k;

  ll bla = (sqrtl(b) - floor(sqrtl(b))) * (DECIMAL_PART - 1);
  ll waza = a + (int)floor(sqrt(b));

  ll test = waza * (DECIMAL_PART * (pow(10, 4 - (int)log(waza))));

  cout << "TESTE >>>>>>> " << test << endl;

  cout << "BLA: " << bla << endl << endl;
  ll q = bla + test;

  cout << "QQQ:  " << q << endl << endl;

  mod = LONG_LONG_MAX;

  cout << "mod:  " << mod << endl;

  ll ans = exp(q, n);

  cout << ans << endl;

  return 0;
}