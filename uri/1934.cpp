#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

string table[MAXN][MAXN];
int linhas[MAXN];
int col[MAXN];

map<string, int> ans;
map<string, bool> achou;

int a, b;
int total = 0;

void show() {
  for (int  i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      cout << table[i][j] << " ";
    } cout << linhas[i] << endl;
  }
  for (int i = 0; i < b; i++) {
    cout << col[i] << "  ";
  } cout << endl;
}

int fazAParada(string curr) {
  int value = ans[curr];
  int changes = 0;
  for (int i = 0; i < a; i++) {
    for(int j = 0; j < b; j++) {
      if (table[i][j].compare(curr) == 0) {
        changes++;
        table[i][j] = "__";
        col[j] -= value;
        linhas[i] -= value;
        // show();
      }
    }
  }
  return changes;
}

int main() {


  cin >> a >> b;

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
        cin >> table[i][j];
    }
    cin >> linhas[i];
  }

  for (int i = 0; i < b; i++) {
    cin >> col[i];
  }

  string curr = "";
  int qtd = 0, other;
  while (total < (a * b)) {
    // show();
    for (int j = 0; j < b; j++) {
    qtd = other = 0;
    curr = "";
    for (int i = 0; i < a; i++) {
      if (table[i][j].compare("__") != 0) {
        if (curr.compare("") == 0) {
          curr = table[i][j];
          qtd++;
        } else if (curr.compare(table[i][j]) == 0) {
          qtd++;
        }
      } else {
        other++;
      }
    }
    if (qtd + other == a) {
      // cout << endl << endl << curr << " col: " << j << endl;
      achou[curr] = true;
      ans[curr] = col[j] / max(qtd, 1);
      total += fazAParada(curr);
    }
  }

  // show();

  for (int i = 0; i < a; i++) {
    qtd = other = 0;
    curr = "";
    for (int j = 0; j < b; j++) {
      if (table[i][j].compare("__") != 0) {
        if (curr.compare("") == 0) {
          curr = table[i][j];
          qtd++;
        } else if (curr.compare(table[i][j]) == 0) {
          qtd++;
        }
      } else {
        other++;
      }
    }
    if (qtd + other == b) {
      achou[curr] = true;
      // cout << endl << endl << curr << " linha: " << i << endl;
      ans[curr] = linhas[i] / max(qtd, 1);
      total += fazAParada(curr);
    }
  }
  }

  // show();

  for (auto waza : ans) {
    if (waza.first.compare("") != 0)
    cout << waza.first << " " << waza.second << endl;
  }

  return 0;
}