"""
https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0
        
        n_0 = 0
        n_1 = 1
        n_2 = 1
        
        for _ in range(3, n + 1):
            n_curr = n_0 + n_1 + n_2
            n_0 = n_1
            n_1 = n_2
            n_2 = n_curr
            
        return n_2
    

if (__name__ == '__main__'):
    solution = Solution()
    
    print(solution.tribonacci(2))
    print(solution.tribonacci(4))
    print(solution.tribonacci(5))
    print(solution.tribonacci(10))
    print(solution.tribonacci(15))
    print(solution.tribonacci(20))
    
    
    