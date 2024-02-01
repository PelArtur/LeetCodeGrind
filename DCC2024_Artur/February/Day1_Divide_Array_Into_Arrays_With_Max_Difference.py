"""
https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01
"""

from typing import List

class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        res = list()
        
        for i in range(0, len(nums), 3):
            if nums[i + 2] - nums[i] > k:
                return []
            res.append([nums[i], nums[i+1], nums[i+2]])
                
        return res
        

if (__name__ == '__main__'):
    solution = Solution()
    test1 = [1,3,4,8,7,9,3,5,1]
    test2 = [1,3,3,2,7,3]
    
    
    print(solution.divideArray(test1, 2))
    print(solution.divideArray(test2, 3))
