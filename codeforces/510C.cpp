#include <bits/stdc++.h>
#define MAXL 4
#define MAXN 10000

using namespace std;

bool letters[MAXL][MAXL];
string names[MAXN];
int head, n, max_size;

int pred[MAXL];

void test() {
  for (int i = 0; i < MAXL; i++) {
    for (int j = 0; j < MAXL; j++) {
      cout << letters[i][j];
    }
    cout << endl;
  }
  cout  << endl << endl;
}

bool isPred(int node, int letter) {
  for (int i = 0; i < MAXL; i++) {
    if (letters[node][i]) {
      if (i == letter)
        return true;
      return isPred(i, letter);
    }
  }
  return false;
}

int nextLetter(int letter) {
  int next = -1;
  for (int i = 0; i < MAXL; i++)
    if (letters[letter][i])
      next = i;
  return next;
}

void setOrd(int letter, int nextPred) {
  int letterNext = nextLetter(letter);
  int letterPred = pred[letter];
  int nextPredNext = nextLetter(nextPred);
  int nextPredPred = pred[nextPred];

  if (letterPred != -1) {
    head = letterNext;
  } else {
    letters[letterPred][letter] = false;
    if (letterNext != -1) {
      letters[letterPred][letterNext] = true;
    }
  }

  if (letterNext != -1) {
    letters[letter][letterNext] = false;
  }

  letters[nextPred][letter] = true;

  if (nextPredNext != -1) {
    letters[letter][nextPredNext] = true;
  }

  pred[letter] = nextPred;
  pred[nextPred] = letterPred;
  pred[nextPredNext] = letter;
}

void build() {
  head = max_size = 0;
  for (int i = 0; i < MAXL; i++) {
    letters[i][i + 1] = true;
    pred[i] = i - 1;
  }
}

void solve() {
  for (int j = 0; j < max_size; j++) {
    for (int i = 1; i < n; i++) {
      if (names[i].size() < j && names[i - 1].size() < j) {
        setOrd(names[i][0] - 'a', names[i - 1][0] - 'a');
      }
      test();
    }
  }
}

void showAlphabet(int node) {
  for(int i = 0; i < MAXL; i++) {
    if (letters[node][i]) {
      cout << (char)(i + 'a');
      showAlphabet(i);
      break;
    }
  }
}

int main() {

  build();

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> names[i];
    max_size = max(max_size, (int)names[i].size());
  }

  solve();

  cout << (char)(head + 'a');
  showAlphabet(head);

  return 0;
}