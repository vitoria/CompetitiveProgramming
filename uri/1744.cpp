#include <bits/stdc++.h>

using namespace std;

int main() {

  long long a, b, ans = 0;
  string s;
  int i, j;

  while (cin >> a >> b) {
    ans = 0;
    cin >> s;

    j = s.size() - 1;
    i = 0;

    while (i < j) {
      if (s[i] == 'W' && s[j] == 'B') {
        ans += min(a, (j - i) * (a - b));
        j--;
        i++;
      } else if (s[j] == 'W') {
        j--;
      } else {
        i++;
      }      
    }

    cout << ans << endl;
    
  }

  return 0;
}