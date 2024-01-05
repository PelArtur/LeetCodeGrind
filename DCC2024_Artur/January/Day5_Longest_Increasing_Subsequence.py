"""
https://leetcode.com/problems/longest-increasing-subsequence/?envType=daily-question&envId=2024-01-05
"""

from typing import List

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1 for _ in range(len(nums))]

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        
        return max(dp)
    

if (__name__ == '__main__'):
    test1 = [10, 9, 2, 5, 3, 7, 101, 18]
    test2 = [0, 1, 0, 3, 2, 3]
    test3 = [7, 7, 7, 7, 7, 7, 7]
    
    print(Solution().lengthOfLIS(test1))
    print(Solution().lengthOfLIS(test2))
    print(Solution().lengthOfLIS(test3))
            