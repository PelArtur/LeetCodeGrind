"""
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/submissions/1159334050/?envType=daily-question&envId=2024-01-28
"""

from typing import Optional, List
from collections import defaultdict

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rows, cols = len(matrix), len(matrix[0])
        sub_sum = [[0 for _ in range(cols)] for _ in range(rows)]
        
        for row in range(rows):
            for col in range(cols):
                top = sub_sum[row - 1][col] if row > 0 else 0
                left = sub_sum[row][col - 1] if col > 0 else 0
                top_left = sub_sum[row - 1][col - 1] if min(row, col) > 0 else 0
                sub_sum[row][col] = matrix[row][col] + top + left - top_left

        res = 0
        for row1 in range(rows):
            for row2 in range(row1, rows):
                count = defaultdict(int)
                count[0] = 1
                for col in range(cols):
                    curr_sum = sub_sum[row2][col] - (
                        sub_sum[row1 - 1][col] if row1 > 0 else 0
                    )
                    diff = curr_sum - target
                    res += count[diff]
                    count[curr_sum] += 1
                    
        return res
        
    
if __name__ == '__main__':
    
    print(Solution().numSubmatrixSumTarget([[0,1,0],[1,1,1],[0,1,0]], 0))
    print(Solution().numSubmatrixSumTarget([[1,-1],[-1,1]], 0))
    print(Solution().numSubmatrixSumTarget([[904]], 0))
