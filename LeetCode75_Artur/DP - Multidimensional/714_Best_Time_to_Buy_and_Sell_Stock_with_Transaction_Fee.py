"""
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        curr, next = [0, 0], [0, 0]
        
        for i in range(n-1, -1, -1):
            curr[1] = max(next[1], next[0] - prices[i])
            curr[0] = max(next[0], prices[i] - fee + next[1])            
            next = curr
            
        return curr[1]
        
    
if __name__ == '__main__':
    solution = Solution()
    
    test1 = [1,3,2,8,4,9]
    test2 = [1,3,7,5,10,3]
    
    print(solution.maxProfit(test1, 2))
    print(solution.maxProfit(test2, 3))

    