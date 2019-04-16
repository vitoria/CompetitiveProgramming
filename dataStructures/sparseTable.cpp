#include <bits/stdc++.h>

using namespace std;

#define MAXL 21
#define MAXN 100010
#define ll long long

int sparseTable[MAXL][MAXN], elements[MAXN], n;

int log(int n) {
    return __builtin_clz(1) - __builtin_clz(n);
}

void build() {
	for(int i = 0; i < n; i++) sparseTable[0][i] = elements[i];

	for(int j = 1; j < MAXL; j++) {
		for(int i = 0; (i + (1 << (j-1))) < n; i++) {
			sparseTable[j][i] = min(sparseTable[j-1][i], sparseTable[j-1][i + (1 << (j-1))]);
		}
	}
}

int query(int l, int r) {
    int lg = log(r - l + 1);
	return min(sparseTable[lg][l], sparseTable[lg][r - (1 << lg) + 1]);
}

int main() {
    ll l, r;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    build();

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}