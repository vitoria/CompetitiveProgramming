#include <bits/stdc++.h>

using namespace std;

int addDigits(int num) {
  unsigned short int digit = (num % 9);
  return num ? digit ? digit : 9 : 0;
}

int main() {

  int n;

  while(cin >> n) {
    cout << addDigits(n) << endl;
  }

  return 0;
}