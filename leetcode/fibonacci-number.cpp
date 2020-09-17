#include <bits/stdc++.h>

using namespace std;

int dp[31];

int fib(int n) {
  if (n == 0 || n == 1) return n;
  if (dp[n] == 0) {
    dp[n] = fib(n - 1) + fib(n - 2);
  }
  return dp[n];
}

int main() {

  int n;

  while (cin >> n) {
    cout << fib(n) << endl;

    for (int i = 0; i < 30; i++) {
      cout << dp[i] << (i < 29 ? " " : "\n");
    }
  }

  return 0;
}