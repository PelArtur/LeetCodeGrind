"""
https://leetcode.com/problems/range-sum-of-bst/?envType=daily-question&envId=2024-01-08
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        return self.postorder(root, low, high)
        
    def postorder(self, root: TreeNode, low: int, high: int) -> int:
        res = 0
        if root.left:
            res += self.postorder(root.left, low, high)
        if root.right:
            res += self.postorder(root.right, low, high)
        if low <= root.val <= high:
            res += root.val
        
        return res
        
        
        
        
        
if (__name__ == '__main__'):
    solution = Solution()

    node1 = TreeNode(1)
    node6 = TreeNode(6)
    node3 = TreeNode(3, node1)
    node7 = TreeNode(7, node6)
    node13 = TreeNode(13)
    node18 = TreeNode(18)
    node5 = TreeNode(5, node3, node7)
    node15 = TreeNode(15, node13, node18)
    node10 = TreeNode(10, node5, node15)
    
    print(solution.rangeSumBST(node10, 1, 18))