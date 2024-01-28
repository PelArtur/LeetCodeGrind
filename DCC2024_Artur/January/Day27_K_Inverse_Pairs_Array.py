"""
https://leetcode.com/problems/k-inverse-pairs-array/?envType=daily-question&envId=2024-01-27
"""

from typing import Optional, List

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        prevN = [0 for _ in range(k + 1)]
        mod = 10 ** 9 + 7
        prevN[0] = 1     #base case
        
        for i in range(1, n + 1):
            currN = [0 for _ in range(k + 1)]
            currN[0] = 1
            for j in range(1, k + 1):
                currN[j] = currN[j - 1] + prevN[j]
                if j >= i:
                    currN[j] -= prevN[j - i]
                    
            prevN = currN
            
        return currN[k] % mod
        
    
if __name__ == '__main__':
    
    print(Solution().kInversePairs(3, 2))
    print(Solution().kInversePairs(3, 1))
    print(Solution().kInversePairs(3, 0))
    print(Solution().kInversePairs(1000, 1000))
