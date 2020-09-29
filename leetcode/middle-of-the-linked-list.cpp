#include <bits/stdc++.h>

using namespace std;

ListNode* middleNode(ListNode* head) {
  int size = 0;
  ListNode* current = head;

  while (current != nullptr) {
    size++;
    current = current->next;
  }        

  for (int i = 0; i < ceil(floor/2); i++) {
    head = head->next;
  }

  return head;

}

int main() {


  return 0;
}