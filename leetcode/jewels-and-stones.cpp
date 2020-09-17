#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string J, string S) {
  bool jewels[256];
  int ans = 0;

  memset(jewels, false, sizeof(jewels));

  for (int i = 0; i < J.size(); i++) jewels[J[i]] = true;

  for (int i = 0; i < S.size(); i++) {
    if (jewels[(int)S[i]]) ans++;
  }

  return ans;
}

int main() {

  string J, S;

  while (cin >> J >> S) {
    cout << numJewelsInStones(J, S) << endl;
  }

  return 0;
}