"""
https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25
"""

from typing import Optional, List
from collections import defaultdict

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2) + 1)] for _ in range(len(text1) + 1)]
        
        for i in range(1, len(text1) + 1):
            for j in range(1, len(text2) + 1):
                dp[i][j] = dp[i - 1][j - 1] + 1 if text1[i - 1] == text2[j - 1] else max(dp[i - 1][j], dp[i][j-1])
                
        return dp[-1][-1]
        
    
if __name__ == '__main__':
    solution = Solution()
    
    test1 = ["abcde", "ace"]
    test2 = ["abc", "abc"]
    test3 = ["abc", "def"]
    
    print(solution.longestCommonSubsequence(test1[0], test1[1]))
    print(solution.longestCommonSubsequence(test2[0], test2[1]))
    print(solution.longestCommonSubsequence(test3[0], test3[1]))
