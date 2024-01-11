"""
https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def __init__(self) -> None:
        self.maxDiff = 0

    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.maxDiff = 0
        self.postorder(root)
        return self.maxDiff
        
    def postorder(self, node: TreeNode) -> tuple:
        currMin = node.val
        currMax = node.val
        
        if not node.left and not node.right:
            return (currMin, currMax)
        
        if node.left:
            left = self.postorder(node.left)
            self.maxDiff = max(self.maxDiff, abs(node.val - left[0]))
            self.maxDiff = max(self.maxDiff, abs((node.val - left[1])))
            currMin = min(currMin, left[0])
            currMax = max(currMax, left[1])
            
        if node.right:
            right = self.postorder(node.right)
            self.maxDiff = max(self.maxDiff, abs(node.val - right[0]))
            self.maxDiff = max(self.maxDiff, abs(node.val - right[1]))
            currMin = min(currMin, right[0])
            currMax = max(currMax, right[1])
            
        return (currMin, currMax)
        
        
if (__name__ == '__main__'):
    solution = Solution()

    tree1Node4 = TreeNode(4)
    tree1Node7 = TreeNode(7)
    tree1Node1 = TreeNode(1)
    tree1Node13 = TreeNode(13)
    tree1Node6 = TreeNode(6, tree1Node4, tree1Node7)
    tree1Node14 = TreeNode(14, tree1Node13, None)
    tree1Node3 = TreeNode(3, tree1Node1, tree1Node6)
    tree1Node10 = TreeNode(10, None, tree1Node14)
    tree1Node8 = TreeNode(8, tree1Node3, tree1Node10)
    
    tree2Node3 = TreeNode(3)
    tree2Node0 = TreeNode(0, tree2Node3, None)
    tree2Node2 = TreeNode(2, None, tree2Node0)
    tree2Node1 = TreeNode(1, None, tree2Node2)
    
    print(solution.maxAncestorDiff(tree1Node8))
    print(solution.maxAncestorDiff(tree2Node1))
