class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
      return self.pathForSum(root, sum, 0, [])

    def isLeaf(self, node: TreeNode) -> bool:
      if node != None and node.left == None and node.right == None:
        return True
      return False

    def pathForSum(self, node: TreeNode, sum: int, currSum: int, path: List[int]) -> List[List[int]]:
      if node is None:
        return []
      currSum += node.val
      path = path + [node.val]
      if self.isLeaf(node):
        if currSum == sum:
          return [path]
        else:
          return []
    
      left = self.pathForSum(node.left, sum, currSum, path)
      right = self.pathForSum(node.right, sum, currSum, path)

      ans = []

      for i in left:
        if len(i) > 0:
          ans.append(i)
      for i in right:
        if len(i) > 0:
          ans.append(i)

      return ans

root = TreeNode(5, TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))), TreeNode(8, TreeNode(13), TreeNode(4, TreeNode(5), TreeNode(1))))

s = Solution()

print(s.pathSum(root, 22))
