# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None or head.next == None:
          return head

        odd = head
        even = head.next
        evenHead = even

        while even != None and even.next != None:
          odd.next = even.next
          odd = odd.next
          even.next = odd.next
          even = even.next

        odd.next = evenHead

        return head

def printLinkedList(head: ListNode, prev=''):
  curr = head
  if len(prev) > 0:
    print(prev)
  while (curr != None):
    print(curr.val)
    curr = curr.next


if __name__ == '__main__':
  head = ListNode(val = 1, next=ListNode(2, next=ListNode(3)))

  printLinkedList(head)

  # print('head', head.val)

  solution = Solution()

  # print

  ans = solution.oddEvenList(head)


  printLinkedList(ans, prev='solution')

# a -> (b) -> c -> (d) -> NULL
# odd: a -> c
# even: b