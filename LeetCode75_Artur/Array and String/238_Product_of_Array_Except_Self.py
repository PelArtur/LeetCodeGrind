"""
 https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75
"""
from typing import Optional, List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1 for _ in range(n)]
        
        pref = 1
        suf = 1
        for i in range(n):
            res[i] *= suf
            suf *= nums[i]
            
            res[n - i - 1] *= pref
            pref *= nums[n - i - 1]
            
        return res            

    
if __name__ == "__main__":
    test1 = [1,2,3,4]
    test2 = [-1,1,0,-3,3]
    
    print(Solution().productExceptSelf(test1))
    print(Solution().productExceptSelf(test2))
