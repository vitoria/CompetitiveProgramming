
#include <bits/stdc++.h>
 
using namespace std;
 
int qtdStair[10000];
 
int main() {
 
    int count = 0, n, before = 0, aux;
 
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (aux > before) {
            qtdStair[count]++;
        } else {
            count++;
            qtdStair[count]++;
        }
        before = aux;
    }
    count++;
    cout << count << endl;
 
    cout << qtdStair[0];
    for (int i = 1; i < count; i++) {
        cout << " " << qtdStair[i];
    }
    cout << endl;
 
    return 0;
}