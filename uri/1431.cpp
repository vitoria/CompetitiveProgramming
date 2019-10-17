#include <bits/stdc++.h>
#define MAX_GRADE 1001
#define MAXN (int)1e4 + 10
 
using namespace std;

int n, m;
int intervals[MAXN];
int grades[MAXN][MAX_GRADE];  

int main() {

  int aux;

  while (scanf("%d", &n) && n != 0) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &intervals[i]);
      for(int j = 0; j < MAX_GRADE; j++)
        grades[i][j] = 0;
      for (int j = 0; j < intervals[i]; j++) {
        scanf("%d", &aux);
        grades[i][aux]++;
      }

      for (int k = 1; k < MAX_GRADE; k++) {
        grades[i][k] += grades[i][k - 1];
      }
    } 

    long long ans = 1e18, acc;

    for (int i = 0; i < MAX_GRADE; i++) {
      acc = 0;
      for (int j = 0; j < n; j++) {
        acc += abs(intervals[j] - (2 * (intervals[j] - grades[j][i])));
      }
      ans = min(ans, acc);
    }

    printf("%lld\n", ans);

  }

  return 0;
}