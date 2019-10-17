#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int n, a;
int ans = 0;
  cin >> n;

  for (int i = 0; i < 5;i++) {
    cin >> a;
    if (a == n) ans ++;
  }

  cout << ans << endl;
  
  return 0; 
}