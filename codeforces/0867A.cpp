#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, a = 0, b = 0;
  string s;

  cin >> n >> s;

  for (int i = 1; i < n; i++) {
    if (s[i-1] == 'S' && s[i] == 'F') a++;
    else if (s[i-1] == 'F' && s[i] == 'S') b++;
  }

  cout << ((a > b) ? "YES" : "NO") << endl;

  return 0;
}