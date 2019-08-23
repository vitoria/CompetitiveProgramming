#include <bits/stdc++.h>
#define ll long long
#define MAXN (int)1e7 + 1

using namespace std;

bool notPrime[MAXN];
vector<int> primes;

bool isPrime(ll n) {
  if (n == 2) return true;
  for (ll i = 2; i <= ceil(sqrt(n)); i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {

  ll n;
  bool ans = false;

  while(cin >> n) {
    ans = false;
    for (; n > 1 && !ans; n--) ans = isPrime(n);
    cout << n + 1 << endl;
  }

  return 0;
}