#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;

  long long prefix[3], acc = 0, ans = 0;

  while(cin >> s) {
    ans = acc = 0;
    prefix[0] = 1; prefix[1] = prefix[2] = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        acc += s[i] - '0';
        ans += prefix[acc % 3];
        prefix[acc % 3]++;
      } else {
        prefix[0] = 1; prefix[1] = prefix[2] = 0;
        acc = 0;
      }
    }

    cout << ans << endl;
  }

  return 0;
}