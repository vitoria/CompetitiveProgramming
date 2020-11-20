# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 != None and t2 != None:
            return TreeNode(val=(t1.val + t2.val), left=self.mergeTrees(t1.left, t2.left), right=self.mergeTrees(t1.right, t2.right))
        if t1 != None:
            return TreeNode(val=t1.val, left=self.mergeTrees(t1.left, None), right=self.mergeTrees(t1.right, None))
        if t2 != None:
            return TreeNode(val=t2.val, left=self.mergeTrees(t2.left, None), right=self.mergeTrees(t2.right, None))
        return None

