#include <bits/stdc++.h>
#define MAXN 7 * (int)1e5

using namespace std;

pair<string, char> cards[MAXN];

int main() {

  int n, ans = 0;
  int qtd_entrance = 0;
  queue<pair<string, char>> clients;

  while(cin >> n && n != 0) {
    qtd_entrance = ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> cards[i].first >> cards[i].second;
      if (cards[i].second == 'E') qtd_entrance++;
    }

    sort(cards, cards + n);

    // for (int i = 0; i < n; i++) {
    //   cout << cards[i].first << endl;
    // }

    qtd_entrance = (n / 2) - qtd_entrance;

    for (int i = 0; i < n; i++) {
      if (cards[i].second == 'E') clients.push(cards[i]);
      else if (cards[i].second == '?' && qtd_entrance > 0) {
        clients.push(cards[i]);
        qtd_entrance--;
      } else {
        clients.pop();
      }

      ans = max((int)clients.size(), ans);
    }

    cout << ans << endl;

  }

  return 0;
}