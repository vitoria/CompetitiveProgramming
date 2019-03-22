#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ll n, tier;
    map<ll, vector<ll>> street;
    ll ans = 0;

    cin >> n;

    for(int i = 0; i < 2 * n; i++) {
        cin >> tier;
        street[tier - 1].push_back(i);
    }

    ans += street[0][0] + street[0][1];
    bool isFirst = true;
    for (int i = 1; i < n; i++) {
        ans += min(abs(street[i-1][0] - street[i][0]) + abs(street[i-1][1] - street[i][1]),
        abs(street[i-1][1] - street[i][0]) + abs(/*  */street[i-1][0] - street[i][1]));
    }
 
    cout << ans << endl;
    
    return 0;
}