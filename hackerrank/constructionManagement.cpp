#include <bits/stdc++.h>

using namespace std;

int minCost(vector<vector<int>> cost) {
    int n = cost.size();
    
    for (int i = 1; i < cost.size(); i++) {
        cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
    }
    
    return min(cost[n-1][0], min(cost[n-1][1], cost[n-1][2]));
}

int main() {

  cout << "a\n";

  return 0;
}