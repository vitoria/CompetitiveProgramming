#include <bits/stdc++.h>
#define MAXN 51

int freq[MAXN];

using namespace std;

int main() {

  int n, a, smallest = INT_MAX;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a;
    freq[a]++;
    if (a < smallest) smallest = a;
  }

  cout << ((freq[smallest] > (n / 2)) ? "Bob" : "Alice") << endl;

  return 0;
}