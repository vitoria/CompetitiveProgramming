#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b){
    return a*b/mdc(a,b);
}

int main() {

  int n, m;

  int v[n];
  for (int i =0; i < n; i++) {
    
  }

  return 0;
}