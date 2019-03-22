#include <bits/stdc++.h>
#define MAX 1000100
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll a[MAX], b[MAX], n, ans = 0, to_every = 0;
map<pll, ll> d;

int main() {
    pll aux;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (a[i] == 0 && b[i] == 0) to_every++;
        else if (b[i] == 0) {
            aux.first = 0;
            aux.second = 0;
            d[aux]++;
        }
        else if (a[i] != 0) {
            ll k = max(a[i], -a[i]);
            ll k1 = max(-b[i], b[i]);
            ll bla = __gcd(max(k1, k), min(k, k1));
            
            if (a[i] < 0 && b[i] < 0) {
                aux.first = k/bla;
                aux.second = k1/bla;
            } else if (a[i] < 0 || b[i] < 0) {
                aux.first = -1 * (k/bla);
                aux.second = k1/bla;
            } else {
                aux.first = k/bla;
                aux.second = k1/bla;
            }

            d[aux]++;
        }
    }

    for (auto x: d) {
        ans = max(ans, x.second);
    }

    cout << (ans + to_every) << endl;

    return 0;
}