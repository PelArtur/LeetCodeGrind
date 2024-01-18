"""
https://leetcode.com/problems/find-peak-element/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1 or nums[0] > nums[1]:
            return 0
        
        if nums[-1] > nums[-2]:
            return len(nums) -1
        
        left = 1
        right = len(nums) - 2
        while left < right:
            mid = left + (right - left) // 2 
            
            if nums[mid - 1] < nums[mid] > nums[mid + 1]:
                return mid
            elif nums[mid] < nums[mid + 1]:
                left = mid + 1
            else:
                right = mid - 1
                
        return left
    

if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = [1,2,3,1]
    test2 = [1,2,1,3,5,6,4]
    
    print(solution.findPeakElement(test1))
    print(solution.findPeakElement(test2))
    
    