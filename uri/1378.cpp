#include <bits/stdc++.h>
#define MAXN (int)1e4 + 1
#define pii pair<int, int>

using namespace std;

double calc_dist(pii p1, pii p2) {
  return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {

  int n;
  pii points[MAXN];
  // double dists[MAXN][MAXN];
  set<pair<pii, int>> ans;
  map<double, int> waza[MAXN];
  int x, y, z;

  while (cin >> n && n != 0) {
    ans.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &points[i].first, &points[i].second);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        double dist = calc_dist(points[i], points[j]);
        waza[i] = 
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        double dist = calc_dist(points[i], points[j]);
        for (int k = 0; k < n; k++) {
          if (i != k && k != j && calc_dist(points[i], points[k]) == dist && calc_dist(points[j], points[k]) != dist) {
            x = min(i, min(j, k));
            y = max(i, max(j, k));
            z = (i + j + k) - x - y;
            ans.insert({{x, y}, z});

            // cout << i << ", " << j << ", " << k << endl;
            // cout << x << ", " << z << ", " << y << endl;
          }
        }
      }
    }
    printf("%d\n", (int)ans.size());
    // cout << ans.size() << endl;
  }

  return 0;
}