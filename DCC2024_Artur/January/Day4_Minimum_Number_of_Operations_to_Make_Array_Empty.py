"""
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-04
"""

from typing import List

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        occurrences = dict()
        res = 0
        
        for num in nums:
            if num not in occurrences:
                occurrences[num] = 0
            occurrences[num] += 1
            
        for num in occurrences:
            if occurrences[num] == 1:
                return -1
            
            if not occurrences[num] % 3:
                res += occurrences[num] / 3
            elif occurrences[num] % 3 == 1:
                res += (occurrences[num] - 4) / 3 + 2
            else:
                res += (occurrences[num] - 2) / 3 + 1
                
        return int(res)
    

if (__name__ == '__main__'):
    test1 = [2, 3, 3, 2, 2, 4, 2, 3, 4]
    test2 = [2, 1, 2, 2, 3, 3]
    
    print(Solution().minOperations(test1))
    print(Solution().minOperations(test2))
            
            
"""
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        count = collections.Counter(nums)
        if 1 in count.values():
            return -1
        return sum((a + 2) // 3 for a in count.values())
"""