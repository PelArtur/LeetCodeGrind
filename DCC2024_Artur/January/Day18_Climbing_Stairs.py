"""
 https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18
"""
from typing import Optional, List

class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        
        prev_prev = 1
        prev = 2
        
        for _ in range(2, n):
            curr = prev + prev_prev
            prev_prev = prev
            prev = curr
            
        return prev
    
if __name__ == "__main__":
    solution = Solution()
    
    test1 = 1
    test2 = 2
    test3 = 5
    test4 = 10
    
    print(solution.climbStairs(test1))
    print(solution.climbStairs(test2))
    print(solution.climbStairs(test3))
    print(solution.climbStairs(test4))
