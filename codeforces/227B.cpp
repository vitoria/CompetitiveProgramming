#include <bits/stdc++.h>
#define MAXN 100010
#define pii pair<int, int>
#define ll long long

using namespace std;

// int elements[MAXN];
int elements_vasya[MAXN];
int elements_petya[MAXN];

int main() {

  int n, aux, m;
  ll ans_a = 0, ans_b = 0;

  cin >> n;

  memset(elements_petya, -1, MAXN);
  memset(elements_vasya, -1, MAXN);

  for (int i = 0; i < n; i++) {
    cin >> aux;
    if (elements_petya[aux] == -1) elements_petya[aux] = i + 1;
    if (elements_vasya[aux] == -1) elements_vasya[aux] = n - i;
    elements_petya[aux] = min(elements_petya[aux], i + 1);
    elements_vasya[aux] = min(elements_vasya[aux], n - i);
  }

  cin >> m;

  for (int i = 0; i < m; i++) {
    cin >> aux;
    ans_a += elements_petya[aux];
    ans_b += elements_vasya[aux];
  }

  cout << ans_a << " " << ans_b << endl;

  return 0;
}