#include <bits/stdc++.h>

#define MAXN int(1e5) + 1

using namespace std;

bool a[MAXN], b[MAXN];

void readInput(bool array[], int size) {
  int x;
  
  memset(array, 0, MAXN);
  
  for (int i = 0; i < size; i++) {
    cin >> x;
    array[x] = true;
  }
}

int main() {
  int n, m;
  int toChangeA, toChangeB;
  
  while (cin >> n >> m && n + m != 0) {
    toChangeA = 0; toChangeB = 0;
    
    readInput(a, n);
    readInput(b, m);
    
    for (int i = 0; i < MAXN; i++) {
      if (a[i] && !b[i]) {
        toChangeA++;
      }
      if (b[i] && !a[i]) {
        toChangeB++;
      }
    }
    
    cout << min(toChangeA, toChangeB) << endl;
  }
  
  return 0;
}