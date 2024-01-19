from typing import List, Dict

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seenValue: Dict[int, int] = dict()
        for idx, number in enumerate(nums):
            if(target - number in seenValue):
                return seenValue[target-number], idx
            seenValue[number] = idx