#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;
  long long int count = 0;

  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    count += s[i] - '0';
  }

  // cout << (s[s.size() - 1] - '0') << endl;

  if (count % 3 == 0) cout << "0\n";
  else if ((count - 1) % 3 == 0) cout << 1 << endl;
  else cout << 2 << endl;

  return 0;
}