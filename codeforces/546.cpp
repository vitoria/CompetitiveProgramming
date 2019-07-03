#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
	int n, k, w;
	ll acc = 0;

	cin >> k >> n >> w;

	for (int i = 1; i <= w; i++) acc = acc + (i * k);
	if (acc <= n) cout << "0\n";
	else cout << (acc - n) << "\n";

	return 0;
}