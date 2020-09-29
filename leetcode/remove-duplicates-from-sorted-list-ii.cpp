#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
  map<int, int> valuesFreq;
  ListNode* ans = new ListNode();
  ListNode* current;

  while (head != nullptr) {
    valuesFreq[head->val]++;
    head = head->next;
  }

  for (auto freq : valuesFreq) {
    if (freq.second == 1) {
      ListNode* temp = new ListNode(freq.first);
      if (ans->next == nullptr) {
        ans->next = temp;
      } else {
        current->next = temp;
      }
      current = temp;
    }
  }

  return ans->next;
}


int main() {

  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));

  // 1, 2, 5
  ListNode* ans = deleteDuplicates(l1);

  while (ans != nullptr) {
    cout << ans->val << ", ";
    ans = ans->next;
  }

  cout << endl;


  return 0;
}