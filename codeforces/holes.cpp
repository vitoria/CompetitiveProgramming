#include <bits/stdc++.h>
#define MAXN (int) 1e5 + 1
#define M (int)ceil(sqrt(MAXN))

using namespace std;

int root;
int n, power[MAXN], q, op, hole, x, y;

int inicio(int id){
  return id * root;
}

int fim(int id){
  return min(n, (id + 1) * root);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  pair <int, int> holes[MAXN];
  root = ceil(sqrt(n));

  for (int i = 0; i < n; i++) {
    cin >> power[i];
  }

  for(int i = 0; i < root; i++){
    for(int j = fim(i) - 1; j >= inicio(i); j--){
      if(power[j] + j >= fim(i)){
        holes[j] = {power[j] +  j, 1};
      }else{
        holes[j] = holes[power[j] + j];
        holes[j].second++;
      }
    }
  }

  while (cin >> op) {
    if (op == 1) {
      cin >> hole;
      hole--;
      int ans = 0;
      while(holes[hole].first < n){
        ans += holes[hole].second;
        hole = holes[hole].first;
      }
      while(power[hole] + hole < n){
        ans++;
        hole += power[hole];
      }
      cout << (hole + 1) << " " << (ans + holes[hole].second) << endl;
    } else {
      cin >> x >> y;
      x--;
      power[x] = y;
      int curr = x / root;
      for(int j = fim(curr) - 1; j >= inicio(curr); j--){
        if (power[j] + j >= fim(curr)) {
          holes[j] = {power[j] + j, 1};
        } else {
          holes[j] = holes[power[j] + j];
          holes[j].second++;
        }   
      }
    }
  }
 
  return 0;
}