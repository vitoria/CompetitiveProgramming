#include <bits/stdc++.h>

using namespace std;

int main() {

  int x, y, z, t1, t2, t3;
  bool useStairs = false;

  cin >> x >> y >> z >> t1 >> t2 >> t3;

  useStairs = (abs(x - y) * t2 + 2 * t3 + abs(x - z) * t2) < (abs(x - y) * t1);

  cout << (useStairs ? "YES" : "NO") << endl;

  return 0;
}