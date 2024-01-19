"""
 https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75
"""
from typing import Optional, List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        max_area = 0
        width = len(height) - 1
        
        while left < right:
            curr_area = width * min(height[left], height[right])
            max_area = max(max_area, curr_area)
            
            if height[left] > height[right]:
                right -= 1
            else:
                left += 1
                
            width -= 1
            
        return max_area

    
if __name__ == "__main__":
    test1 = [1,8,6,2,5,4,8,3,7]
    test2 = [1,1]
    
    print(Solution().maxArea(test1))
    print(Solution().maxArea(test2))
