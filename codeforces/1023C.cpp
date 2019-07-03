#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, k, open = 0;
  string s, ans = "";
  queue<char> parentheses;

  cin >> n >> k;
  cin >> s;

  for (int i = 0; open < (k / 2); i++) {
    parentheses.push(s[i]);
    if (s[i] == '(') open++;
  }

  int rest = k - parentheses.size();
  
  while(!parentheses.empty()) {
    cout << parentheses.front();
    parentheses.pop();
  }
  for (int i = 0; i < rest; i++) {
    cout << ")";
  }

  cout << endl;

  return 0;
}