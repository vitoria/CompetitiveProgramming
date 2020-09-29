#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  ListNode* ans = new ListNode();
  ListNode* last;
  deque<int> values;

  while (head != nullptr) {
    values.push_back(head->val);
    head = head->next;
  }

  while (!values.empty()) {
    ListNode* current = new ListNode(values.back());
    if (ans->next == nullptr) {
      ans->next = current;
    } else {
      last->next = current;
    }

    last = current;
    values.pop_back();
  }

  return ans->next;
}

int main() {

  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));

  ListNode* ans = reverseList(l1);

  while (ans != nullptr) {
    cout << ans->val << ", ";
    ans = ans->next;
  }

  cout << endl;


  return 0;
}