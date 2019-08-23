#include <bits/stdc++.h>
#define ll long long int
#define MAXN (int)30
#define M 1e5

using namespace std;

ll distancia[MAXN][MAXN];
ll graph[MAXN][MAXN];

void floydWarshall() {

  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      distancia[i][j] = M;
      if (i == j) distancia[i][j] = 0;
    }
  }

  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      if (graph[i][j] != 0)
      distancia[i][j] = graph[i][j] - 1;
      if (i == j) distancia[i][j] = 0;
    }
  }

  for(int k = 0; k < MAXN; k++) {
    for(int i = 0; i < MAXN; i++) {
      for(int j = 0; j < MAXN; j++) {
        distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
      }
    }
  }
}

int main() {

  string s, t;
  ll n, z;
  char x, y;
  ll ans = 0;

  cin >> s >> t;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    if (graph[x - 'a'][y - 'a'] == 0) {
      graph[x - 'a'][y - 'a'] = z + 1;
    } else {
      graph[x - 'a'][y - 'a'] = min(graph[x - 'a'][y - 'a'], z + 1);
    }
  }

  floydWarshall();

  // for (int i = 0; i < MAXN; i++) 
  //   for (int j = 0; j < MAXN; j++) {
  //     if (distancia[i][j] < M && distancia[i][j] > 1) {
  //       cout << ((char) ('a' + i)) << " - " << ((char) ('a' + j)) << ": " << distancia[i][j] << endl;
  //     }
  //   }

  //   cout << endl << endl;

  char current;
  int changeCost;
  ll a, b;

  if (s.size() != t.size()) {
    ans = -1;
  } else {
    for (int i = 0; i < s.size() && ans != -1; i++) {
      a = s[i] - 'a'; b = t[i] - 'a';
      if (a != b) {
        changeCost = M;
        for (int j = 0; j < MAXN; j++) {
          if ((distancia[a][j] + distancia[b][j]) < changeCost) {
            changeCost = distancia[a][j] + distancia[b][j];
            current = j + 'a';
          }
        }
        if (changeCost == M) ans = -1;
        else {
          ans += changeCost;
          s[i] = current;
          // cout << "current: " << current << "     changing cost: " << changeCost << endl;
        }
      }
    }
  }

  // for (int i = 0; i < 10; i++) {
  //   for (int j = 0; j < 10; j++) {
  //     cout << distancia[i][j] << ", ";
  //   }
  //   cout << endl;
  // }

  if (ans != -1) {
    cout << ans << endl << s << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}