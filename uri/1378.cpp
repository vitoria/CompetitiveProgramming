#include <bits/stdc++.h>
#define MAXN (int)1e4 + 1
#define ll long long
#define pii pair<ll, ll>

using namespace std;

int n;
pii points[MAXN];
int ans;

ll calc_dist(pii p1, pii p2) {
  ll x = p1.first - p2.first;
  ll y = p1.second - p2.second;
  return (x * x) + (y * y);
}

int main() {
  ll dist;

  while (scanf("%d", &n) && n != 0) {
    ans = 0;
    unordered_map<ll, int> dists;
    dists.reserve(n);
    for (int i = 0; i < n; i++) {
      scanf("%lld %lld", &points[i].first, &points[i].second);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
          dist = calc_dist(points[i], points[j]);
          if (dist > 0) dists[dist]++;
      }
      for (auto p : dists) {
        ans += (p.second * (p.second - 1)) / 2.0;
      }
      dists.clear();
    }

    printf("%d\n", ans);
  }

  return 0;
}