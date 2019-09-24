#include <bits/stdc++.h>

using namespace std;

map<char, float> notas = {
  {'W', 1},
  {'H', 1 / 2.0},
  {'Q', 1 / 4.0},
  {'E', 1 / 8.0},
  {'S', 1 / 16.0},
  {'T', 1 / 32.0},
  {'X', 1 / 64.0}
};

int main() {

  string music;
  int ans;
  float acc;

  while (cin >> music && music[0] != '*') {
    ans = acc = 0;
    for (int i = 0; i < music.size(); i++) {
      if (music[i] == '/') {
        if (acc == 1) ans++;
        acc = 0;
      } else {
        acc += notas[music[i]];
      }
    }

    if (acc == 1) ans++;

    cout << ans << endl;
  }

  return 0;
}