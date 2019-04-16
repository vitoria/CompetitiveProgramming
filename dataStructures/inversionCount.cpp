#include <bits/stdc++.h>
#define MAXN 200100
#define pii pair<int, int>
#define ll long long

using namespace std;

pii elements[MAXN];
ll ans;
int bit[MAXN];

void update(int index, int value) {
  for (int i = index; i <= MAXN; i += (i & -i)) {
    bit[i] += value;
  }
}

ll query(int position) {
  ll result = 0;
  for (int i = position; i > 0; i -= (i & -i)) {
    result += bit[i];
  }
  return result;
}

int main() {

  int n, m, k;

  cin >> n;

  while(n--) {
    cin >> m;
    for (int i = 1; i <= m; i++) {
      cin >> k;
      elements[i - 1] = {k, i};
    }

    sort(elements, elements + m);

    memset(bit, 0, sizeof(bit));

    ans = 0;
    
    while(m--) {
      ans += query(elements[m].second);
      update(elements[m].second, 1);
    }

    cout << ans << endl;

  }

  return 0;
}