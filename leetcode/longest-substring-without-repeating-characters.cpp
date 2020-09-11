#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
  if (s.size() == 0) return 0;

  int charPosition[256];
  memset(charPosition, -1, sizeof(charPosition));
  int left = 0;
  int ans = 0;

  for (int right = 1; right < s.size(); right++) {
    charPosition[s[left]] = left;
    if (charPosition[s[right]] >= left) {
      ans = max(ans, right - left);
      left = charPosition[s[right]] + 1;
    }
    charPosition[s[right]] = right;
    ans = max(right - left, ans);
  }

  ans = max(ans, ((int)s.size() - left));

  return ans;
}

int main() {

  string a;

  cin >> a;

  cout << lengthOfLongestSubstring(a) << endl;

  return 0;
}