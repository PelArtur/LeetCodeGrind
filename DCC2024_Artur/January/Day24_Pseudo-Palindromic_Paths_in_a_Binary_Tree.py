"""
  https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
"""

from typing import Optional, List
from collections import defaultdict


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

class Solution:
    def __init__(self) -> None:
        self.occurrence = defaultdict(int)
        self.oddNum = 0
        self.res = 0
    
    def pseudoPalindromicPaths(self, root: Optional[TreeNode]) -> int:
        self.dfs(root)
        return self.res
        
    def dfs(self, root: Optional[TreeNode]) -> None:
        if not root:
            return None
        
        self.occurrence[root.val] += 1
        is_odd = 1 if self.occurrence[root.val] % 2 else -1
        self.oddNum += is_odd
        
        if not root.left and not root.right:
            self.res += 1 if self.oddNum < 2 else 0
        else:
            self.dfs(root.left)
            self.dfs(root.right)
        
        self.occurrence[root.val] -= 1   
        self.oddNum -= is_odd
        
          
if __name__ == "__main__":
    tree1Node6 = TreeNode(1)
    tree1Node5 = TreeNode(1)
    tree1Node4 = TreeNode(3)
    tree1Node3 = TreeNode(3, tree1Node4, tree1Node5)
    tree1Node2 = TreeNode(1, None, tree1Node6)
    tree1Node1 = TreeNode(2, tree1Node3, tree1Node2)
    
    tree2Node6 = TreeNode(1)
    tree2Node5 = TreeNode(3, None, tree2Node6)
    tree2Node4 = TreeNode(1)
    tree2Node3 = TreeNode(1)
    tree2Node2 = TreeNode(1, tree2Node4, tree2Node5)
    tree2Node1 = TreeNode(2, tree2Node2, tree2Node3)
    
    tree3Node1 = TreeNode(9)
        
    print(Solution().pseudoPalindromicPaths(tree1Node1))
    print(Solution().pseudoPalindromicPaths(tree2Node1))
    print(Solution().pseudoPalindromicPaths(tree3Node1))
