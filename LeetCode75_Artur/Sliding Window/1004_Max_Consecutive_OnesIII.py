"""
 https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75
"""
from typing import Optional, List

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left, right = 0, 0
        num_zeros, num_ones = 0, 0
        max_ones = 0
        
        while right < len(nums):                
            if nums[right]:
                num_ones += 1
            else:
                num_zeros += 1
                
            while num_zeros > k:
                if nums[left]:
                    num_ones -= 1
                else:
                    num_zeros -= 1
                left += 1
            
            max_ones = max(max_ones, num_ones + num_zeros)
            right += 1
        
        return max_ones

    
if __name__ == "__main__":
    test1 = [1,1,1,0,0,0,1,1,1,1,0]
    test2 = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
    
    print(Solution().longestOnes(test1, 2))
    print(Solution().longestOnes(test2, 3))
