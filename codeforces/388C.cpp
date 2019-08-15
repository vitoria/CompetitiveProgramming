#include <bits/stdc++.h>
#define MAXN 1010

using namespace std;

deque<int> matriz[MAXN];
int intervals[MAXN][2];
bool isEmpty[MAXN];

int main() {

  int n, m;
  long long sa = 0, sb = 0;
  int qtdEmpty = 0;
  int aux;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> m;
    for (int j = 0; j < (m/2); j++) {
      cin >> aux;;
      sa += aux;
    }

    if (m % 2 == 1) {
      cin >> aux;
      matriz[i].push_back(aux);
    } else {
      isEmpty[i] = true;
      qtdEmpty++;
    } 

    for (int j = 0; j < (m/2); j++) {
      cin >> aux;;
      sb += aux;
    }
  }

  // cout << "Waza\n";


  int position;
  int maior = 0;
  while (qtdEmpty < n) {
    maior = 0;
    for (int i = 0; i < n; i++) {
      if (!isEmpty[i] && matriz[i][0] > maior) {
        maior = matriz[i][0]; position = i;
      }
    }
    sa += maior;
    matriz[position].pop_front();

    // cout << maior << endl;

    if (matriz[position].size() == 0 && !isEmpty[position]) {
      isEmpty[position] = true; qtdEmpty++;;
    }

    maior = 0;
    for (int i = 0; i < n; i++) {
      if (!isEmpty[i] && matriz[i][matriz[i].size() - 1] > maior) {
        maior = matriz[i][matriz[i].size() - 1]; position = i;
      }
    }
    sb += maior;
    matriz[position].pop_back();

    // cout << maior << endl;

    if (matriz[position].size() == 0 && !isEmpty[position]) {
      isEmpty[position] = true; qtdEmpty++;;
    }

  }

  cout << sa << " " << sb << endl;

  return 0;
}