#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, a;
  bool isHard = false;

  cin >> n;

  while(n) {
    cin >> a;
    isHard = isHard || a;
    n--;
  }

  cout << (isHard ? "hard" : "easy") << endl;

  return 0;
}