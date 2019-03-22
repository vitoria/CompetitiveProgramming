#include <bits/stdc++.h>
#define MAX 100010

using namespace std;

int n, ans = 0, k = 0;
long long v[MAX];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v, v+n);
    
    for (int i = 0; i < n; i++) {
        while (k < n && (v[k] - v[i]) <= 5) {
            k++;
        }
        ans = max(ans, (k - i));
    }

    ans = max(ans, (k - i));
    cout << ans << endl;

    return 0;
}