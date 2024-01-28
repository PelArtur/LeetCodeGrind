"""
https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26
"""

from typing import Optional, List
from collections import defaultdict

class Solution:
    
    def __init__(self) -> None:
        self.m = -1
        self.n = -1
        self.visited = defaultdict(int)
    
    def dfs(self, row: int, col: int, movesLeft: int) -> int:
        if row < 0 or row >= self.m or col < 0 or col >= self.n:
            return 1
        if not movesLeft:
            return 0
        
        currState = (row, col, movesLeft)
        if currState not in self.visited:
            self.visited[currState] = (self.dfs(row - 1, col, movesLeft - 1) +
                                       self.dfs(row + 1, col, movesLeft - 1) +
                                       self.dfs(row, col - 1, movesLeft - 1) +
                                       self.dfs(row, col + 1, movesLeft - 1))
        
        return self.visited[currState]
    
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        self.m = m
        self.n = n
        
        return self.dfs(startRow, startColumn, maxMove) % (10**9 + 7)
        
    
if __name__ == '__main__':
    
    print(Solution().findPaths(2, 2, 2, 0, 0))
    print(Solution().findPaths(1, 3, 3, 0, 1))
