"""
 https://leetcode.com/problems/sum-of-subarray-minimums/?envType=daily-question&envId=2024-01-20
"""
from typing import Optional, List

class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        stack = []
        mod = 10 ** 9 + 7
        res = 0
        
        for i in range(len(arr)):
            while stack and arr[i] < arr[stack[-1]]:
                ind = stack.pop()
                left = ind - stack[-1] if stack else ind + 1
                right = i - ind
                res = (res + left * right * arr[ind]) % mod
            stack.append(i)
            
        for j in range(len(stack)):
            left = stack[j] - stack[j - 1] if j > 0 else stack[j] + 1
            right = len(arr) - stack[j]
            res = (res + left * right * arr[stack[j]]) % mod
            
        return res        
    
if __name__ == "__main__":
    solution = Solution()
    
    test1 = [3,1,2,4]
    test2 = [11,81,94,43,3]
    
    print(solution.sumSubarrayMins(test1))
    print(solution.sumSubarrayMins(test2))
