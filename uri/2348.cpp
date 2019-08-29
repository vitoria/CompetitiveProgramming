#include <bits/stdc++.h>
#define MAXN (int)1e5

using namespace std;

int main() {

  int n;
  int grade[MAXN];
  int aux[MAXN];
  double areaTotal = 0;

  // cout << M_PI << endl;

  while(cin >> n) {

    areaTotal = 0;

    // Get the angle in radians
    double angulo = (360.0 / (n)) * M_PI / 180.0;
    double sin_angle = sin(angulo) * (1.0 / 2.0);

    for (int i = 0; i < n; i++) {
      cin >> aux[i];
    }
    sort(aux, aux + n);
    int a = 1;
    int b = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        grade[b] = aux[i];
        b++;
      } else {
        grade[n - a] = aux[i];
        a++;
      }
    }

    for (int i = 1; i < n; i++) {
      areaTotal += sin_angle * grade[i] * grade[i - 1]; 
    }
    areaTotal += sin_angle * grade[0] * grade[n - 1];

    double ans = floor(areaTotal);
    double waza = floor((areaTotal - ans) * 1000.0) / 1000.0;
    // double ans = (int)floor(areaTotal * 1000) / 1000.0;
    // printf("%.3f\n", (ans + waza));
    printf("%.3lf\n", areaTotal);
  }


  return 0;
}