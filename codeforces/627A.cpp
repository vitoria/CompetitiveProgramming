#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll sum, waza;
ll dpzona[4][100];

ll solve(int carryIn, int index) {
  if (dpzona[carryIn][index] != -1) return dpzona[carryIn][index];
  ll shift = 1LL << index;
  if (shift > sum && shift > waza) return dpzona[carryIn][index] = 1 - carryIn;
  if (waza & shift) { // São diferentes
    if (sum & shift) { // Soma deu 1
      if (carryIn) return dpzona[carryIn][index] = 0;
      return dpzona[carryIn][index] = 2 * solve(0, index + 1);
    } else {
      if (!carryIn) return dpzona[carryIn][index] = 0;
      return dpzona[carryIn][index] = 2 * solve(1, index + 1);
    }
  } else {
    if (sum & shift) {
      if (!carryIn) return dpzona[carryIn][index] = 0;
      return dpzona[carryIn][index] = solve(0, index + 1) + solve(1, index + 1);
    } else {
      if (carryIn) return dpzona[carryIn][index] = 0;
      return dpzona[carryIn][index] = solve(0, index + 1) + solve(1, index + 1);
    }
  }
}

int main() {
  cin >> sum >> waza;

  memset(dpzona, -1, sizeof(dpzona));  
  if ( sum == waza) {
    cout << solve(0, 0) - 2 << endl;  
  } else cout << solve(0, 0) << endl;

  return 0;
}