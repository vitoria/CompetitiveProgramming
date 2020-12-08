class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
      return self.calLongestZigZag(root, '', 0)

    def calLongestZigZag(self, node: TreeNode, side: string, pathSize: int):
      if node is None:
        return -1
      if node.left is None and node.right is None:
        return 0
      if side is 'left':
        return max(self.calLongestZigZag(node.left, 'left', 0), self.calLongestZigZag(node.right, 'right', pathSize) + 1)
      if side is 'right':
        return max(self.calLongestZigZag(node.left, 'left', pathSize) + 1, self.calLongestZigZag(node.right, 'right', 0))
      return max(self.calLongestZigZag(node.left, 'left', pathSize) + 1, self.calLongestZigZag(node.right, 'right', pathSize) + 1)
