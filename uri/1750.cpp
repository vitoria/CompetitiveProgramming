#include <bits/stdc++.h>
#define MAXN (int)1e5

using namespace std;

int v[MAXN];

int main() {

  int n;
  int a = 0, b = 0;

  while(cin >> n) {
    a = b = 0;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);

    sort(v, v + n);

    for (int i = 0; i < n - 1; i += 2) {
      a += min(abs(v[i] - v[i + 1]), 24 - abs(v[i] - v[i + 1]));
    }

    for (int i = 1; i < n - 1; i += 2) {
      b += min(abs(v[i] - v[i + 1]), 24 - abs(v[i] - v[i + 1]));
    }
    b += min(abs(v[0] - v[n - 1]), 24 - abs(v[0] - v[n - 1]));

    printf("%d\n", min(a, b));
  }

  return 0;
}