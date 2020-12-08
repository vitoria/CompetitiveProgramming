class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    root = None
    def findTarget(self, node: TreeNode, k: int) -> bool:
      if self.root is None:
        self.root = node
      if node is None:
        return False
      a = self.contains(self.root, k, node.val)
      if a != None and a != node:
        return True
      return self.findTarget(node.left, k) or self.findTarget(node.right, k)
        

    def contains(self, node: TreeNode, k: int, n: int) -> bool:
      if node is None:
        return None
      if node.val + n == k:
        return node
      if node.val + n < k:
        return self.contains(node.right, k, n)
      return self.contains(node.left, k, n)