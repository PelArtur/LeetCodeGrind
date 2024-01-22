"""
https://leetcode.com/problems/set-mismatch/?envType=daily-question&envId=2024-01-22
"""

from typing import Optional, List
from collections import defaultdict

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        occurrence = defaultdict(int)
        total_sum = 0
        n = len(nums)

        for num in nums:
            occurrence[num] += 1
            total_sum += num
            if occurrence[num] == 2:
                duplicated_num = num
            
        mised_num = int((n * (n + 1)) / 2 - (total_sum - duplicated_num))
        
        return [duplicated_num, mised_num]
        
    
if __name__ == '__main__':
    solution = Solution()
    
    test1 = [1, 2, 2, 4]
    test2 = [1, 1]
    
    print(solution.findErrorNums(test1))
    print(solution.findErrorNums(test2))
