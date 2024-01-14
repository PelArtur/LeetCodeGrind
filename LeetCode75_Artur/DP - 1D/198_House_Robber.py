"""
https://leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        prev_prev = nums[0]
        prev = max(nums[0], nums[1])
        
        for i in range(2, len(nums)):
            curr = max(prev_prev + nums[i], prev)
            prev_prev = prev
            prev = curr
            
        return prev
        
        
    
if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = [1, 2, 3, 1]
    test2 = [2, 7, 9, 3, 1]
    test3 = [2, 1, 1, 2]
    
    print(solution.rob(test1))
    print(solution.rob(test2))
    print(solution.rob(test3))
    
    
"""
Тут варіант без виділення додаткової пам'яті для
масиву dp, але з використанням трьох додаткових 
змінних
"""