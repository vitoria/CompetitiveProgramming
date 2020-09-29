#include <bits/stdc++.h>

using namespace std;

ListNode* removeElements(ListNode* head, int val) {
  ListNode* ans = new ListNode();
  ListNode* current;

  while (head != nullptr) {
    if (head->val != val) {
      ListNode* temp = new ListNode(head->val);
      if (ans->next == nullptr) {
        ans->next = temp;
      } else {
        current->next = temp;
      }

      current = temp;
    }
    head = head->next;
  }


  return ans->next;
}

int main() {


  return 0;
}