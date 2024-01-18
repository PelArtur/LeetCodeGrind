"""
 https://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import List, Optional
from collections import defaultdict

class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        rows = defaultdict(int)
        
        for row in grid:
            rows[tuple(row)] += 1
            
        col = [0 for _ in range(len(grid))]
        res = 0
        for j in range(len(grid)):
            for i in range(len(grid)):
                col[i] = grid[i][j]
                
            col_tuple = tuple(col)
            if col_tuple in rows:
                res += rows[col_tuple]
                
        return res
    

if __name__ == "__main__":
    solution = Solution()
    
    test1 = [[3,2,1],[1,7,6],[2,7,7]]
    test2 = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
    
    print(solution.equalPairs(test1))
    print(solution.equalPairs(test2))
