# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
      curr = head
      prev = curr
      startIndex = m

      while m > 1:
        m -= 1
        n -= 1
        prev = curr
        curr = curr.next

      temp = self.reverseNodes(curr, n)

      if startIndex == 1:
        return temp
      if prev != temp:
        prev.next = temp

      return head

    def reverseNodes(self, node: ListNode, n: int) -> ListNode:
      if node is None:
        return node

      curr = node
      first = curr
      last = curr

      while n > 0 and curr != None:
        n -= 1
        print(curr.val)
        temp = curr.next
        curr.next = first
        first = curr
        curr = temp
      
      last.next = curr
      
      return first

      
        

def printLinkedList(head: ListNode, prev=''):
  curr = head
  if len(prev) > 0:
    print(prev)
  while (curr != None):
    print(curr.val)
    curr = curr.next


if __name__ == '__main__':
  # head = ListNode(val = 1, next=ListNode(2, next=ListNode(3, next=ListNode(4, next=ListNode(5)))))
  head = ListNode(val=3, next=ListNode(val=5))

  printLinkedList(head)

  # print('head', head.val)

  solution = Solution()

  # print

  ans = solution.reverseBetween(head, 1, 2)
  # ans = solution.reverseNodes(head, 2)


  printLinkedList(ans, prev='solution')
  print('solution', head == head, head == ListNode(val=2), head == ListNode(val=5))



        # for i in range(m-1):
      #   prev = curr
      #   curr = curr.next
      #   n -= 1

      # # reverseHead = 
      # tail = curr
      # reverse = curr

      # while reverse != None and n > 0:
      #   temp = reverse.next
      #   temp.next = reverse
      #   reverse = temp
      #   n -= 1

      # curr.next = reverse
      # lastOfInterval.next = reverse.next

      # A -> B -> C -> D -> NULL
      # B -> A -> C
      #  A -> B



          # def bringTheLastToFront(self, node: ListNode) -> ListNode:
    #   if node is None or node.next is None:
    #     return node
      
    #   temp = self.reverseNodes(node.next)
    #   node.next = temp.next
    #   temp.next = node

    #   return temp