class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    maxDepht = -1

    def rightSideView(self, root: TreeNode) -> List[int]:
        return self.calNodesView(root, 0)

    def calNodesView(self, node: TreeNode, depht: int):
        depht += 1

        if node is None:
            return []
        if depht > self.maxDepht:
            self.maxDepht = depht
            return [node.val] + self.calNodesView(node.right, depht + 1) + self.calNodesView(node.left, depht + 1)
        return self.calNodesView(node.right, depht + 1) + self.calNodesView(node.left, depht + 1)

    
