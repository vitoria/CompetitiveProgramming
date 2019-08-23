#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, c, s, x, acc;
  int ans;

  while (cin >> n >> c >> s) {
    acc = 1;
    ans = 0;
    if (s == 1) ans = 1;
    for (; c; c--) {
      cin >> x;
      if (x == 1) {
        acc += 1;
        if (acc > n) acc = 1;
      } else {
        acc -= 1;
        if (acc < 1) {
          acc = n;
        }
      }
      if (acc == s) ans++;
    }
    
    cout << ans << endl;  

  }

  return 0;
}