"""
 https://leetcode.com/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

class Solution:
    def __init__(self):
        self.res = []
    
    def solve(self, root: Optional[TreeNode], tree_height: int) -> None:
        if not root:
            return None
        if tree_height == len(self.res):
            self.res.append(root.val)
            
        self.solve(root.right, tree_height + 1)
        self.solve(root.left, tree_height + 1)
 
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        self.solve(root, 0)
        return self.res
        
        
        
            
            
if __name__ == "__main__":
    tree1Node5 = TreeNode(5)
    tree1Node4 = TreeNode(4)
    tree1Node3 = TreeNode(3, None, tree1Node4)
    tree1Node2 = TreeNode(2, None, tree1Node5)
    tree1Node1 = TreeNode(1, tree1Node2, tree1Ntree1Node3ode7)
    
    tree2Node3 = TreeNode(3)
    tree2Node1 = TreeNode(1, None, tree2Node3)
        
    Solution().rightSideView(tree1Node1)
    Solution().rightSideView(tree2Node1)
