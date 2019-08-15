#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000100

using namespace std;

vector<int> primos;
int v[MAXN];
ll despojados[MAXN];
int waza[MAXN];
ll q;

void crivo() {
  for (int i = 2; i < MAXN; i++) {
    if (v[i] != -1) {
      primos.push_back(i);
      for (int k = 2; (k * i) < MAXN; k++) {
        v[k * i] = -1;
        if (despojados[k * i] != 0) {
          despojados[k * i] *= i;
          if (despojados[k * i] == k * i) waza[k * i] = true, q++;
        } else {
          despojados[k * i] = i;
        }
      }
    }
  }
}

int main() {

  ll n, bla;
  int ans = 0;

  cin >> n;

  crivo();

  for (int i = 6; i < MAXN; i++) {
    if (waza[i] && n % i == 0) ans++;
  }

  cout << q << endl;

  cout << ans << endl;


  return 0;
}