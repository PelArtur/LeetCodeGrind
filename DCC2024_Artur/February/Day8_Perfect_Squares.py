"""
https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08
"""

from typing import List
from collections import defaultdict

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [i for i in range(n+1)]
        for i in range(3, n + 1):
            j = 1
            while j * j <= i:
                dp[i] = min(dp[i], dp[i - j*j] + 1)
                j += 1
        
        return dp[n]
        

if __name__ == '__main__':
    
    print(Solution().numSquares(12))
    print(Solution().numSquares(13))
