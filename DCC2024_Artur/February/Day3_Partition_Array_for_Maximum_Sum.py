"""
https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03
"""

from typing import List

class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        dp = [0 for _ in range(len(arr))]
        
        curr_max = 0
        for i in range(k):
            curr_max = max(curr_max, arr[i])
            dp[i] = curr_max * (i + 1)
        
        for i in range(k, len(arr)):
            curr_max = arr[i]
            for j in range(i, i -k, - 1):
               curr_max = max(curr_max, arr[j])
               dp[i] = max(dp[i], curr_max * (i - j + 1) + dp[j - 1])
        
        return dp[-1]
        

if __name__ == '__main__':
    
    print(Solution().maxSumAfterPartitioning([1,15,7,9,2,5,10], 3))
    print(Solution().maxSumAfterPartitioning([1,4,1,5,7,3,6,1,9,9,3], 4))
    print(Solution().maxSumAfterPartitioning([1], 1))
