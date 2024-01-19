"""
 https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19
"""
from typing import Optional, List

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        
        for i in range(1, n):
            matrix[i][0] += min(matrix[i - 1][0], matrix[i - 1][1])
            matrix[i][n - 1] += min(matrix[i - 1][n - 1], matrix[i - 1][n - 2])
            
            for j in range(1, n - 1):
                matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i - 1][j + 1]))
                
        min_path = 9999999999
        for col in matrix[n-1]:
            min_path = min(min_path, col)
            
        return min_path
        
    
if __name__ == "__main__":
    solution = Solution()
    
    test1 = [[2,1,3],[6,5,4],[7,8,9]]
    test2 = [[-19,57],[-40,-5]]
    
    print(solution.minFallingPathSum(test1))
    print(solution.minFallingPathSum(test2))
