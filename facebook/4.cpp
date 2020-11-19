#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getUmbrellas' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER requirement
 *  2. INTEGER_ARRAY sizes
 */

int dp [1e6 + 1];
int MAXN = 1e9;
int getUmbrellas(int requirement, vector<int> sizes) {  
  for(int i = 1; i <= requirement; i++) dp[i] = MAXN;

  for(int i = 1; i <= requirement; i++) {
    for(int j = 0; j < sizes.size(); j++) {
      if(sizes[j] <= i) dp[i] = min(dp[i], 1 + dp[i - sizes[j]]);
    }
  }
  int result = dp[requirement];
  return (result == MAXN ? -1 : result);
}

