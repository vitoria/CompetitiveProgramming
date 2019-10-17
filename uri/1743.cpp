#include <bits/stdc++.h>

using namespace std;

int main() {

  int a[5], b[5];
  bool isValid = true;

  while (cin >> a[0]) {
    isValid = true;

    for (int i = 1; i < 5; i++) scanf("%d", &a[i]);
    for (int i = 0; i < 5; i++) scanf("%d", &b[i]);

    for (int i = 0; i < 5; i++) {
      isValid = isValid && (a[i] != b[i]);
    }

    cout << (isValid ? "Y" : "N") << endl;
  }

  return 0;
}