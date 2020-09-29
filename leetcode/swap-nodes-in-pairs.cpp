#include <bits/stdc++.h>

using namespace std;

ListNode* swapPairs(ListNode* head) {
  ListNode* ans = new ListNode();
  ListNode* current;
  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next->next;
    head->next = temp;

    if (ans-> next == nullptr) {
      ans->next = hea
    }

    
  }
}

int main() {



  return 0;
}