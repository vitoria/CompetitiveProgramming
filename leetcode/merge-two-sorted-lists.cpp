#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* ans = new ListNode();
  ListNode* last;
  
  while (l1 != nullptr || l2 != nullptr) {
    ListNode* temp = new ListNode();
    if (l2 == nullptr || (l1 != nullptr && l1->val < l2->val)) {
        temp->val = l1->val;
        l1 = l1->next;
    } else {
      temp->val = l2->val;
      l2 = l2->next;
    }

    if (ans->next == nullptr) {
      ans->next = temp;
    } else {
      last->next = temp;
    }

    last = temp;

  }

  return ans->next;
} 

int main() {

  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  ListNode* ans = mergeTwoLists(l1, l2);

  while (ans != nullptr) {
    cout << ans->val << ", ";
    ans = ans->next;
  }

  cout << endl;

  return 0;
}