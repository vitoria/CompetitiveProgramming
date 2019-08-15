#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int main() {

  // dó dó# ré ré# mi fá fá# sol sol# lá lá# si
  string tom[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
  int interval[] = { 2, 2, 1, 2, 2, 2, 1 };
  int notas[MAXN];
  bool valid[MAXN];
  int ans = 0;
  bool correct;
  int acc =0;

  int n;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> notas[i];
    notas[i] = (notas[i] - 1) % 12;
  }

  // for (int k = 0; k < n; k++) cout << notas[k] << ", ";
  //   cout << endl << endl;

  for (int i = 0; i < 12 && !correct; i++) {
    memset(valid, false, MAXN);
    acc = i;
    for (int j = 0; j < 8; j++) {
      acc += interval[j];
      valid[acc % 12] = true;
    }
    // for (int k = 0; k < 10; k++) cout << valid[k] << ", ";
    // cout << endl << endl;
    correct = true;
    // for (int k = 0; k < 12; k++) cout << valid[k] << ", ";
    // cout << endl << endl;
    for (int j = 0; j < n && correct; j++) correct = correct && valid[notas[j]];
    ans = i;
  }

  // cout << "ans: " << ans << endl;
  cout << ((!correct) ? "desafinado" : tom[ans]) << endl;

  return 0;
}