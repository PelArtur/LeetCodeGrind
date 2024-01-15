"""
https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[1 for _ in range(n)] for _ in range(m)]
        
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
                
        return dp[-1][-1]
        
    
if __name__ == '__main__':
    solution = Solution()
    
    test1 = [3, 7]
    test2 = [3, 2]
    test3 = [1, 1]
    
    print(solution.uniquePaths(test1[0], test1[1]))
    print(solution.uniquePaths(test2[0], test2[1]))
    print(solution.uniquePaths(test3[0], test3[1]))
    