"""
https://leetcode.com/problems/path-sum-iii/submissions/1148731970/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.pathNum = 0
        
    def internalDFS(self, root: Optional[TreeNode], targetSum: int):
        if not root:
            return
        
        if root.val == targetSum:
            self.pathNum += 1
            
        self.internalDFS(root.left, targetSum - root.val)
        self.internalDFS(root.right, targetSum - root.val)
    
    def externalDFS(self, root: Optional[TreeNode], targetSum: int):
        if root:
            self.internalDFS(root, targetSum)
            self.externalDFS(root.left, targetSum)
            self.externalDFS(root.right, targetSum)
    
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> int:
        self.externalDFS(root, targetSum)
        return self.pathNum
        
        
if (__name__ == '__main__'):
    tree1Node1 = TreeNode(1)
    tree1Nodem2 = TreeNode(-2)
    tree1Node_3 = TreeNode(3)
    tree1Node11 = TreeNode(11)
    tree1Node2 = TreeNode(2, None, tree1Node1)
    tree1Node3 = TreeNode(3, tree1Node_3, tree1Nodem2)
    tree1Nodem3 = TreeNode(-3, None, tree1Node11)
    tree1Node5 = TreeNode(5, tree1Node3, tree1Node2)
    tree1Node10 = TreeNode(10, tree1Node5, tree1Nodem3)
    
    tree2Node1 = TreeNode(1)
    tree2Node_5 = TreeNode(5)
    tree2Node2 = TreeNode(2)
    tree2Node7 = TreeNode(7)
    tree2Node_4 = TreeNode(4, tree2Node_5, tree2Node1)
    tree2Node13 = TreeNode(13)
    tree2Node11 = TreeNode(11, tree2Node7, tree2Node2)
    tree2Node8 = TreeNode(8, tree2Node13, tree2Node_4)
    tree2Node4 = TreeNode(4, tree2Node11, None)
    tree2Node5 = TreeNode(5, tree2Node4, tree2Node8)
    
    
    tree3Node5 = TreeNode(5)
    tree3Node4 = TreeNode(4, tree3Node5)
    tree3Node3 = TreeNode(3, tree3Node4)
    tree3Node2 = TreeNode(2, tree3Node3)
    tree3Node1 = TreeNode(1, tree3Node2)
    
    print(Solution().pathSum(tree1Node10, 8))
    print(Solution().pathSum(tree2Node5, 22))
    print(Solution().pathSum(tree3Node1, 3))