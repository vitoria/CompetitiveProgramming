#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  int temp, left = 0, right = nums.size() - 1;

  while (left < right) {
    if (nums[right] != val && nums[left] == val) {
      temp = nums[right];
      nums[right] = nums[left];
      nums[left] = temp;
    }

    if (nums[left] != val) left++;
    if (nums[right] == val) right--;
  }

  return nums.size() == 0 || nums[left] == val ? left : left + 1;
}

int main() {

  vector<int> nums{2};

  int len = removeElement(nums, 3);

  cout << "len: " << len << endl;

  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << (i < nums.size() - 1 ? " " : "\n");
  }

  return 0;
}