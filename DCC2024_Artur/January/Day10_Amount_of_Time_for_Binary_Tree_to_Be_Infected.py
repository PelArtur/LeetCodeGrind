"""
https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
"""

from typing import Optional, List
from collections import defaultdict, deque

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def __init__(self) -> None:
        self.graph = defaultdict(int)
    
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        self.graph = defaultdict(int)
        self.graph[root.val] = []
        self.convert_to_undirected(root)

        
        return self.bfs(start)
        
    def convert_to_undirected(self, node: TreeNode) -> None:
        if not node:
            return None
    
        if node.left:
            self.graph[node.val].append(node.left.val)
            self.graph[node.left.val] = [node.val]
            self.convert_to_undirected(node.left)
        if node.right:
            self.graph[node.val].append(node.right.val)
            self.graph[node.right.val] = [node.val]
            self.convert_to_undirected(node.right)
            
    def bfs(self, start: int) -> int:
        queue = deque()
        visited = dict()
        dist = dict()
        
        for val in self.graph:
            visited[val] = 0
            dist[val] = 0
        
        queue.append(start)
        visited[start] = 1
        dist[start] = 0
        
        while queue:
            currNode = queue.popleft()
            for neigh in self.graph[currNode]:
                if not visited[neigh]:
                    queue.append(neigh)
                    visited[neigh] = 1
                    dist[neigh] = dist[currNode] + 1
                    
        return dist[currNode]
        
        
if (__name__ == '__main__'):
    solution = Solution()

    tree1Node2 = TreeNode(2)
    tree1Node9 = TreeNode(9)
    tree1Node6 = TreeNode(6)
    tree1Node10 = TreeNode(10)
    tree1Node4 = TreeNode(4, tree1Node9, tree1Node2)
    tree1Node3 = TreeNode(3, tree1Node10, tree1Node6)
    tree1Node5 = TreeNode(5, None, tree1Node4)
    tree1Node1 = TreeNode(1, tree1Node5, tree1Node3)
    
    tree2Node5 = TreeNode(5)
    tree2Node4 = TreeNode(4, None, tree2Node5)
    tree2Node3 = TreeNode(3, None, tree2Node4)
    tree2Node2 = TreeNode(2, None, tree2Node3)
    tree2Node1 = TreeNode(1, None, tree2Node2)
    
    tree3Node5 = TreeNode(5)
    tree3Node4 = TreeNode(4)
    tree3Node3 = TreeNode(3, None, tree3Node5)
    tree3Node2 = TreeNode(2, tree3Node3, tree3Node4)
    tree3Node1 = TreeNode(1, None, tree3Node2)
    
    print(solution.amountOfTime(tree1Node1, 3))
    print(solution.amountOfTime(tree2Node1, 4))
    print(solution.amountOfTime(tree3Node1, 4))
