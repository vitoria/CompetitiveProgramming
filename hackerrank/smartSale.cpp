#include <bits/stdc++.h>

using namespace std;

int deleteProducts(vector<int> ids, int m) { 
    vector<pair<int, int>> nums; 
    unordered_map<int, int> freq; 
    int toDelete = 0; 
  
    for (int i = 0; i < ids.size(); i++) {
      freq[ids[i]]++; 
    }
  
    for (auto item : freq) {
      nums.push_back({ item.second, item.first });
    }
  
    sort(nums.begin(), nums.end()); 
  
    for (int i = 0; i < nums.size(); i++) { 
        if (nums[i].first <= m) { 
            m -= nums[i].first; 
            toDelete++; 
        } 
        else {
          nums.size() - toDelete;
        }
    } 

    return nums.size() - toDelete; 
} 

int main() {

  int n, k, aux;

  cin >> n >> k;

  vector<int> nums;

  for (int i = 0; i < n; i++) {
    cin >> aux;

    nums.push_back(aux);
  }

  cout << deleteProducts(nums, k) << endl;

  return 0;
}