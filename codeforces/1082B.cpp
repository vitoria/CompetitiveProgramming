#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int acum[n];
    memset(acum, 0, sizeof acum);
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'G') {
            acum[i] = 1;
            if (i != 0)acum[i] += acum[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (acum[i] != 0) {
            acum[i] = max(acum[i], acum[i + 1]);
        }
    }
    int qtd = 0;
    bool catraca = true;
    for (int i = 0; i < n; i++) {
        if (acum[i] == 0) {
            catraca = true;
        } else {
            if (catraca) {
                qtd++;
                catraca = false;
            }
        }
    }
    if (qtd == 0) {
        cout << "0\n";
    } else if (qtd == 1) {
        for (int i = 0; i < n; i++) {
            if (acum[i] != 0) {
                cout << acum[i] << endl;
                return 0;
            }
        }
    } else  if (qtd == 2) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, acum[i] + 1);
            if (acum[i] == 0 && i > 0 && i + 1 < n) {
                ans = max(ans, acum[i - 1] + acum[i + 1]);
            }
        }
        cout << ans << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, acum[i] + 1);
            if (acum[i] != 0 && i + 2 < n && acum[i + 1] == 0) {
                ans = max(ans, acum[i] + 1 + acum[i + 2]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}