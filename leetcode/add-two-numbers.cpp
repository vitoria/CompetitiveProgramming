#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addToEnd(ListNode* a, ListNode* node) {
  ListNode* list = a;
  while (list->next != nullptr) {
    list = list->next;
  }

  list->next = node;
}
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* ans = new ListNode();
  int currentSum, sumToNext = 0;

  while (l1 != nullptr && l2 != nullptr) {
    currentSum = l1->val + l2->val + sumToNext;
    sumToNext = currentSum / 10;

    ListNode* temp = new ListNode(currentSum % 10);

    if (ans == nullptr) ans = temp;
    else addToEnd(ans, temp);

    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != nullptr) {
    currentSum = l1->val + sumToNext;
    sumToNext = currentSum / 10;
    ListNode* next = new ListNode(currentSum % 10);
    addToEnd(ans, next);
    l1 = l1->next;
  }

  while (l2 != nullptr) {
    currentSum = l2->val + sumToNext;
    sumToNext = currentSum / 10;
    ListNode* next = new ListNode(currentSum % 10);
    addToEnd(ans, next);
    l2 = l2->next;
  }

  if (sumToNext > 0) addToEnd(ans, new ListNode(sumToNext));

  return ans->next;

}

int main() {

  ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(5)));
  ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(5)));

  ListNode* ans = addTwoNumbers(l1, l2);

  while (ans != nullptr) {
    cout << ans->val;
    ans = ans->next;
  }

  cout << endl;

  return 0;
}