"""
https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import List
from collections import defaultdict

class Solution:
    def __init__(self) -> None:
        self.n = 0
        self.visited = []
        self.graph = defaultdict(list)
    
    def dfs(self, root: int):
        self.visited[root] = 1
        
        for neigh in self.graph[root]:
            if not self.visited[neigh]:
                self.dfs(neigh)
    
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        self.n = len(isConnected)
        self.visited = [0 for _ in range(self.n)]
        
        for i in range(self.n):
            for j in range(self.n):
                if isConnected[i][j]:
                    self.graph[i].append(j)
        
        provincesNum = 0
        for i in range(self.n):
            if not self.visited[i]:
                provincesNum += 1
                self.dfs(i)
            
        return provincesNum


if __name__ == "__main__":
    test1 = [[1,1,0],[1,1,0],[0,0,1]]
    test2 = [[1,0,0],[0,1,0],[0,0,1]]
    
    print(Solution().findCircleNum(test1))    
    print(Solution().findCircleNum(test2))    
