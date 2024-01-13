"""
https://leetcode.com/problems/count-good-nodes-in-binary-tree/?envType=study-plan-v2&envId=leetcode-75
"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

        
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        return dfs(root, root.val)


def dfs(node: TreeNode, currMax: int) -> int:
    if not node:
        return 0
        
    goodNode = 0
    if node.val >= currMax:
        goodNode += 1
        currMax = node.val
            
    return goodNode + dfs(node.left, currMax) + dfs(node.right, currMax)

node1 = TreeNode(3)
node2 = TreeNode(1)
node3 = TreeNode(3)
node4 = TreeNode(4)
node5 = TreeNode(1)
node6 = TreeNode(5)

node1.left = node2
node1.right = node4
node2.left = node3
node4.left = node5
node4.right = node6

print(Solution().goodNodes(node1))
