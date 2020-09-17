#include <bits/stdc++.h>

using namespace std;

int hammingDistance(int x, int y) {
  unsigned int diff = x ^ y, ans = 0;
  while (diff) {
    if (diff % 2 == 1) ans++;
    diff = diff>>1;
  } 
  return ans;
}

int main() {

  int x, y;

  while (cin >> x >> y) {
    int result = hammingDistance(x, y);
    cout << "Result: " << result << endl;
  }

  return 0;
}