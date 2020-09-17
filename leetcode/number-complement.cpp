#include <bits/stdc++.h>

using namespace std;

int findComplement(int num) {
  int qtyDigits = floor(log2(num)) + 1, maxNum;
  if (qtyDigits >= 31) maxNum = 2147483647;
  else maxNum = ((1 << qtyDigits) - 1);
  return maxNum ^ num;
}

int main() {

  int n;

  while (cin >> n) {
    cout << findComplement(n) << endl;
  }

  return 0;
}