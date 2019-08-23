#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b){
  // if (a == 1 || b == 1) return max(a, b);
    return a*b/mdc(a,b);
}

int main() {

  int n, m, a, b, ans = 0;
  int aux;

  cin >> n >> m >> a;
  aux = a;

  cout << mmc(1, 10) << endl;;

  for (int i = 1; i < n; i++) {
    cin >> a;
    aux = mmc(aux, a);
  }

  a = aux;
  b = 0;
  ans = 1;  

  for (int i = 0; i <= 1e6; i++) {
    aux = mmc(a, i);
    if (aux > b && aux < m) {
      b = aux;
      ans = i;
    }
  }

  cout << ans << endl;

  return 0;
}