"""
https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

        
class Solution:
    def __init__(self) -> None:
        self.__longest_len = 0
    
    def dfs(self, root: Optional[TreeNode], is_left: bool, curr_len: int) -> None:
        if not root:
            return 
        
        if curr_len > self.__longest_len:
            self.__longest_len = curr_len
            
        if is_left:
            self.dfs(root.left, True, 1)
            self.dfs(root.right, False, curr_len + 1)
        else:
            self.dfs(root.left, True, curr_len + 1)
            self.dfs(root.right, False, 1)
    
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.dfs(root.left, True, 1)
        self.dfs(root.right, False, 1)
        
        return self.__longest_len
        
        
if __name__ == "__main__":
    tree1Node8 = TreeNode(1)
    tree1Node7 = TreeNode(1, None, tree1Node8)
    tree1Node6 = TreeNode(1)
    tree1Node5 = TreeNode(1, None, tree1Node7)
    tree1Node4 = TreeNode(1, tree1Node5, tree1Node6)
    tree1Node3 = TreeNode(1)
    tree1Node2 = TreeNode(1, tree1Node3, tree1Node4)
    tree1Node1 = TreeNode(1, None, tree1Node2)
    
    tree2Node7 = TreeNode(1)
    tree2Node6 = TreeNode(1)
    tree2Node5 = TreeNode(1, None, tree2Node7)
    tree2Node4 = TreeNode(1, tree2Node5, tree2Node6)
    tree2Node3 = TreeNode(1)
    tree2Node2 = TreeNode(1, None, tree2Node4)
    tree2Node1 = TreeNode(1, tree2Node2, tree2Node3)
    
    tree3Node1 = TreeNode(1)
    
    print(Solution().longestZigZag(tree1Node1))
    print(Solution().longestZigZag(tree2Node1))
    print(Solution().longestZigZag(tree3Node1))