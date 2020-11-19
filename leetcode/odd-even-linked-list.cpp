#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {

  if (head == nullptr || head->next ==nullptr) {
    return head;
  }

  ListNode* ans = head, curr = head;
  ListNode* odd;


  while (curr.next != nullptr && curr.next.next != nullptr)

}

int main() {




  return 0;
}


/**

1 -> 2 -> 3 -> 4 -> 5
o         

**/