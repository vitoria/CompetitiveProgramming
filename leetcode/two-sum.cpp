#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> bla, ans;
  for (int i = 0; i < nums.size(); i++) bla.push_back(nums[i]);
  sort(nums.begin(), nums.end());
  int left = 0, right = nums.size() - 1;
  long long sum = 0;

  while (left < nums.size() && right > -1 && nums[left] + nums[right] != target) {
    sum = nums[right] + nums[left];
    if (sum > target) right--;
    else if (sum < target) left++;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (bla[i] == nums[left] || bla[i] == nums[right]) {
      ans.push_back(i);
    }
  }

  return ans;
}

int main() {

  int n, aux;
  vector<int> nums;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> aux;
    nums.push_back(aux);
  }

  cin >> aux;

  vector<int> ans = twoSum(nums, aux);

  cout << ans[0] << ", " << ans[1] << endl;

  return 0;
}