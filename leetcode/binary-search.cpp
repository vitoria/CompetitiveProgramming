#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
int binarySearch(int left, int right, int target) {
  if (left <= right) {
    int middle = (left + right) / 2;

    cout << middle << endl;

    if (arr[middle] == target) return middle;
    if (arr[middle] > target) return binarySearch(left, middle - 1, target);
    return binarySearch(middle + 1, right, target);
  }

  return -1;
}

int search(vector<int>& nums, int target) {
  arr = nums;
  return binarySearch(0, nums.size() - 1, target);
}

int main() {

  vector<int> nums = {-1};

  // for (int i = 0; i < nums.size(); i++) {
  //   cout << nums[i];
  // }

  cout << search(nums, -1) << endl;

  return 0;
}