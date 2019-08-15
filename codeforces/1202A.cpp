#include <bits/stdc++.h>

using namespace std;

int main() {

  int n;
  string a, b;
  int pos_a = 0, pos_b = 0;
  int ans;

  cin >> n; 
  
  while (n) {

    cin >> a >> b;

    // cout << "a: " << a << "b: " << b << endl << endl;

    for (int i = (a.size() - 2); i >= 0; i--) {
      // cout << "i: " << i << endl;
      if (a[i] == '1') {
        pos_a = i; break;
      }
    }

    for (int i = b.size() - 1; i >= 0; i--) {
      if (b[i] == '1') {
        pos_b = i; break;
      }
    }

    // cout << pos_a << " " << pos_b << endl << endl;

    if (a.size() > b.size()) {
      pos_b += a.size() - b.size();
    } else {
      pos_a += b.size() - a.size();
    }

    ans = pos_b - pos_a;

    n--;

    cout << ((ans < 0) ? 0 : ans) << endl;
  }


  return 0;
}