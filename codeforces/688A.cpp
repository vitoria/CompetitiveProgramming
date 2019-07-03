#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000

using namespace std;

ll schedule[MAXN];

int main() {

  int n, d;
  int ans = 0, count = 0;
  string all = "", day;

  cin >> n >> d;

  for (int i = 0; i < n; i++) all += '1';

  for (int i = 0; i < d; i++) {
    cin >> day;
    if (all.compare(day) == 0) ans = max(ans, count), count = 0;
    else count++;
  }

  cout << max(ans, count) << endl;

  return 0;
}