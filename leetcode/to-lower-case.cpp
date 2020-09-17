#include <bits/stdc++.h>

using namespace std;

string toLowerCase(string str) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 'a' - 'A';
    }
  }
  return str;
}

int main() {

  string s;

  while(cin >> s) {
    cout << toLowerCase(s) << endl;
  }

  return 0;
}