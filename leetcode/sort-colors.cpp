#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& nums) {
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << (i < nums.size() - 1 ? " " : "\n");
  }
}

void sortColors(vector<int>& nums) {
  int qtyColor[3];
  memset(qtyColor, 0, sizeof(qtyColor));

  for (int i = 0; i < nums.size(); i++) qtyColor[nums[i]]++;

  for (int i = 0; i < nums.size(); i++) {
    if (qtyColor[0] > 0) {
      nums[i] = 0; qtyColor[0]--;
    } else if (qtyColor[1] > 0) {
      nums[i] = 1; qtyColor[1]--;
    } else {
      nums[i] = 2; qtyColor[2]--;
    }
  }

}

int main() {

  vector<int> nums{0};

  sortColors(nums);

  cout << "Result: ";

  print(nums);

  
  return 0;
}