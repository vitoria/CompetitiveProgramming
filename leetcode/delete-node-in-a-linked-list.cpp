#include <bits/stdc++.h>

using namespace std;

void deleteNode(ListNode* node) {
  while (node->next != nullptr) {
    node-> val = node->next->val;
    if (node->next->next == nullptr) {
      node->next = nullptr;
    } else {
      node = node->next;
    }
  }       
}

int main() {

  

  return 0;
}