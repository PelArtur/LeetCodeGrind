"""
 https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        

class Solution:
    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root or root.val == key and not root.left and not root.right:
            return None
        
        parent = root
        curr = root
        
        while True:
            if not curr:
                return root
            
            if curr.val == key:
                break
            
            parent = curr
            if key < curr.val:
                curr = curr.left
            else:
                curr = curr.right
                
        newCurr = None
        
        if curr.right and not curr.left:
            newCurr = curr.right
        elif curr.left and not curr.right:
            newCurr = curr.left
        elif curr.left and curr.right:
            parentCurr = curr
            newCurr = curr.right
            
            while newCurr.left:
                parentCurr = newCurr
                newCurr = newCurr.left
                
            if parentCurr.left.val == newCurr.val:
                parentCurr.left = newCurr.right
            else:
                parentCurr.right = newCurr.right
                
            newCurr.left = curr.left
            newCurr.right = curr.right
        
        if root.val == key:
            return newCurr
        else:
            if parent.left and parent.left.val == curr.val:
                parent.left = newCurr
            else:
                parent.right = newCurr
                
        return root
            
            
if __name__ == "__main__":
    tree1Node2 = TreeNode(2)
    tree1Node4 = TreeNode(4)
    tree1Node7 = TreeNode(7)
    tree1Node3 = TreeNode(3, tree1Node2, tree1Node4)
    tree1Node6 = TreeNode(6, None, tree1Node7)
    tree1Node5 = TreeNode(5, tree1Node3, tree1Node6)
    
    tree2Node7 = TreeNode(7)
    tree2Node15 = TreeNode(15)
    tree2Node8 = TreeNode(8, tree2Node7, None)
    tree2Node10 = TreeNode(10, tree2Node8, tree2Node15)
    tree2Node4 = TreeNode(4)
    tree2Node5 = TreeNode(5, tree2Node4, tree2Node10)
    tree2Node2 = TreeNode(2)
    tree2Node3 = TreeNode(3, tree2Node2, tree2Node5)
        
    Solution().deleteNode(tree1Node5, 3)
    Solution().deleteNode(tree2Node3, 5)
