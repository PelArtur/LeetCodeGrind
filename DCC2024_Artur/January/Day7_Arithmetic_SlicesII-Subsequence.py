"""
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/?envType=daily-question&envId=2024-01-07
"""

from typing import List
from collections import defaultdict


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        dp = [defaultdict(int) for _ in range(len(nums))]
        res = 0
        
        for i in range(1, len(nums)):
            for j in range(i):
                diff = nums[i] - nums[j]
                
                res += dp[j][diff]
                
                dp[i][diff] += dp[j][diff] + 1
                
        return res


if (__name__ == '__main__'):
    solution = Solution()
    test1 = [2,4,6,8,10]
    test2 = [7,7,7,7,7]
    
    
    print(solution.numberOfArithmeticSlices(test1))
    print(solution.numberOfArithmeticSlices(test2))
