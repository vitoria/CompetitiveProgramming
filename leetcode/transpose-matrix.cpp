#include <bits/stdc++.h>

using namesapce std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
  vector<vector<int>> transposted(A[0].size(), vector<int>(A.size()));
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      transposted[j][i] = A[i][j];
    }
  }

  return transposted;
}

int main() {

  return 0;
}