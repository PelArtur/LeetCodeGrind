"""
https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        numsMax = min(nums)
        secondMax = numsMax
        
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] >= numsMax:
                numsMax = nums[i]
            elif nums[i] >= secondMax:
                secondMax = nums[i]
            else:
                return True
            
        return False
        
    
if (__name__ == '__main__'):
    solution = Solution()

    test1 = [1,2,3,4,5]
    test2 = [5,4,3,2,1]
    test3 = [2,1,5,0,4,6]
    
    print(solution.increasingTriplet(test1))
    print(solution.increasingTriplet(test2))
    print(solution.increasingTriplet(test3))
    