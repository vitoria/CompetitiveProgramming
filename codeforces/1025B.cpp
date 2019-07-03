#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define MAXN 1000000

using namespace std;

pii arr[MAXN];

int main() {

  int n;
  ll max_number = 0;
  int i;

  cin >> n;

  for (i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    max_number = max(max_number, max(arr[i].first, arr[i].second));
  }

  cout << max_number << endl;

  bool valid;
  for (int i = 2; i <= sqrt(max_number) && !valid; i++) {
    cout << "i: " << i << endl;
    valid = true;
    for (int j = 0; j < n && valid; j++) {
      if (arr[i].first % i != 0 && arr[i].second % i != 0) valid = false;
    }
  }

  if (!valid) {
    cout << -1 << endl;
  } else {
    printf("%d\n", i);
  }

  return 0;
}