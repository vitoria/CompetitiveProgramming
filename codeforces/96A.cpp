#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;
  char current;
  int count = 1;

  cin >> s;

  current = s[0];

  for (int i = 1; i < s.size() && count < 7; i++) {
    if (s[i] == current) count++;
    else current = s[i], count = 1;
  }

  cout << ((count == 7) ? "YES\n" : "NO\n");

  return 0;
}