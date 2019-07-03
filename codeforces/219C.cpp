#include <bits/stdc++.h>
 
using namespace std;
 
char getColor(char a, char b) {
  if (a != 'A' && b != 'A') return 'A';
  if (a != 'B' && b != 'B') return 'B';
  return 'C';
}
 
int main() {
 
  int n, m;
  string colors;
  string ans1 = "", ans2 = "";
  int count1 = 0, count2 = 0;
 
  cin >> n >> m;
 
  cin >> colors;
 
  if (m > 2) {
    ans1 += colors[0];
    for (int i = 1; i < n; i++) {
      if (colors[i] == ans1[i-1]) {
        count1++;
        if (i < (n - 1) && m > 2) {
          ans1 += getColor(ans1[i-1], colors[i+1]);
        } else {
          ans1 += getColor(ans1[i-1], ans1[i-1]);
        }
      } else {
        ans1 += colors[i];
      }
    }

    count2 = 1e9;
  } else {
    for (int i = 0; i < n; i++) {
      ans1 += (i % 2 == 0) ? 'A' : 'B';
      ans2 += (i % 2 == 0) ? 'B' : 'A';
      if (ans1[i] != colors[i]) count1++;
      if (ans2[i] != colors[i]) count2++;
    }
  }
 
  cout << min(count1, count2) << endl;
 
  if (count1 == min(count1, count2)) {
    cout << ans1 << endl;
  } else {
    cout << ans2 << endl;
  }
 
  return 0;
}