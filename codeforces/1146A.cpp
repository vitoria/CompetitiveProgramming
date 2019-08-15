#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;
  int freq_a = 0;

  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') freq_a++;
  }

  cout << ((freq_a * 2 - 1 > s.size()) ? s.size() : (freq_a * 2 - 1)) << endl;

  return 0;
}