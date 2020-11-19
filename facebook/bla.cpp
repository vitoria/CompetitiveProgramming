#include<bits/stdc++.h> 
using namespace std; 

int efficientCabScheduling(int n, vector<int> cabTripTime) {
  int l = 0;
  int h = ;
  int m = h + (l - h) / 2;
  while (l < h) {
    m = h + (l - h) / 2;
    int trips = 0;
    for (int k : cabTripTime) {
      trips += (m / k);
    }
    if (trips == n) {
      break;
    } else if (trips < n) {
      l = m + 1;
    } else {
      h = m - 1;
    }
  }
  return m;
}

int main() 
{ 
    vector<int> cabTripTime =  {23, 28, 8, 20, 28, 27, 18};
    int n = 19;
    cout << solve(n, cabTripTime) << endl; 
    return 0; 
} 