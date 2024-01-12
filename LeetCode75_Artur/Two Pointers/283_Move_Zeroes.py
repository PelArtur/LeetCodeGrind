from typing import List

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        flag = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                flag += 1
            else:
                nums[i-flag] = nums[i]
        for i in range(len(nums)-flag, len(nums)):
            nums[i] = 0
