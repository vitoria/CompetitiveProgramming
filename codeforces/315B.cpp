#include <bits/stdc++.h>
#define MAXN (int)1e5 + 1
#define ll long long

using namespace std;

ll values[MAXN];

int main() {

  ll n, m, opt, x, y;
  ll acc = 0;

  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> values[i];

  do {
    cin >> opt >> x;
    if (opt == 1) {
      cin >> y;
      values[x] = y;
    } else if (opt == 2) {
      acc += x;
    } else {
      cout << values[x] + acc << endl;
    }
  } while (m--);



  return 0;
}