"""
https://leetcode.com/problems/leaf-similar-trees/?envType=daily-question&envId=2024-01-09
"""

from typing import Optional, List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.leafs1 = []
        self.leafs2 = []
    
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        self.leafs1 = []
        self.leafs2 = []
        self.__postorder(root1, self.leafs1)
        self.__postorder(root2, self.leafs2)
        
        return self.leafs1 == self.leafs2
        
    def __postorder(self, root: TreeNode, lst: List[int]) -> None:
        if not root.left and not root.right:
            lst.append(root.val)

        if root.left:
            self.__postorder(root.left, lst)
        if root.right:
            self.__postorder(root.right, lst)
        
        
if (__name__ == '__main__'):
    solution = Solution()

    tree1Node7 = TreeNode(7)
    tree1Node4 = TreeNode(4)
    tree1Node9 = TreeNode(9)
    tree1Node8 = TreeNode(8)
    tree1Node6 = TreeNode(6)
    tree1Node2 = TreeNode(2, tree1Node7, tree1Node4)
    tree1Node5 = TreeNode(5, tree1Node6, tree1Node2)
    tree1Node1 = TreeNode(1, tree1Node9, tree1Node8)
    tree1Node3 = TreeNode(3, tree1Node5, tree1Node1)
    
    tree2Node7 = TreeNode(7)
    tree2Node4 = TreeNode(4)
    tree2Node9 = TreeNode(9)
    tree2Node8 = TreeNode(8)
    tree2Node6 = TreeNode(6)
    tree2Node2 = TreeNode(2, tree1Node9, tree1Node8)
    tree2Node5 = TreeNode(5, tree1Node6, tree1Node7)
    tree2Node1 = TreeNode(1, tree1Node4, tree1Node2)
    tree2Node3 = TreeNode(3, tree1Node5, tree1Node1)
    
    print(solution.leafSimilar(tree1Node3, tree2Node3))
    
    tree3Node3 = TreeNode(3)
    tree3Node2 = TreeNode(2)
    tree3Node1 = TreeNode(1, tree3Node2, tree3Node3)
    
    tree4Node3 = TreeNode(3)
    tree4Node2 = TreeNode(2)
    tree4Node1 = TreeNode(1, tree3Node3, tree4Node2)
    
    print(solution.leafSimilar(tree3Node1, tree4Node1))