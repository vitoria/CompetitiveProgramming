#include <bits/stdc++.h>
#define MAXN (int)1e5
#define ll long long

using namespace std;

int main() {

  int n, k;
  int arr[MAXN];
  int pot[MAXN];
  ll acc = 0, rm = 0;
  
  while(cin >> n >> k) {
    priority_queue<int, vector<int>, greater<int>> waza;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      acc += arr[i];
    }

    for (int i = 0; i < k; i++) pot[i] = 0;
    for (int i = 0; i < ceil((n - k) / (k + 1.0)); i++) {
      for (int j = (k + (i * (k + 1))); j < (k + ((i + 1) * (k + 1))) && j < n; j++) {
        pot[j] = i + 1;
      }
    }

    for (int i = k; i < n; i++) {
      waza.push(arr[i]);
      rm += arr[i];
      if (waza.size() > pot[i]) {
        rm -= waza.top();
        waza.pop();
      }
    }

    // for (int i = 0; i < n; i++) {
    //   cout << arr[i] << " - " << pot[i] << endl;
    // }

    cout << (acc - rm) << endl;

    acc = 0; rm = 0;
  }

  return 0;
}