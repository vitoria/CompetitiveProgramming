#include <bits/stdc++.h>
#define MAX 1000007
#define ll long long int

using namespace std;

vector <int> primes,divisores(MAX), power(MAX), waza[MAX];
bitset<MAX> is_prime;

void crivo(){
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    divisores[1] = 1;

    for(int i = 2; i < MAX; i++){
        if(is_prime[i]){
            primes.push_back(i);
            power[i] = 1;
            divisores[i] = 2;
        }

        for(int j = 0; j < primes.size() && i*primes[j] < MAX; j++){
            is_prime[i*primes[j]] = 0;
            if(i%primes[j] == 0){
                waza[i*primes[j]].push_back(i);
                power[i*primes[j]] = power[i] + 1;
                divisores[i*primes[j]] = divisores[i]/(power[i]+1) *(power[i*primes[j]]+1);
                break;
            }
            else{
                power[i*primes[j]] = 1;
                divisores[i*primes[j]] = divisores[i]*2;
                waza[i*primes[j]].push_back(i);
            }
        }
    }
}


int main(){
    crivo();
    
    ll n;

    cin >> n;
    printf("%d\n", divisores[n]);
    for (int i = 0; i < waza[n].size(); i++) {
      cout << waza[n][i] << ", ";
    }
    cout << endl;
    return 0;
}