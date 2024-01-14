"""
https://leetcode.com/problems/successful-pairs-of-spells-and-potions/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        
        res = []
        len_potions = len(potions)
        for spell in spells:
            l = 0
            r = len_potions - 1
            
            while l <= r:
                mid = l + (r - l) // 2
                if potions[mid] * spell < success:
                    l = mid + 1
                else:
                    r = mid - 1
                    
            res.append(len_potions - l)
            
        return res
    
if (__name__ == '__main__'):
    solution = Solution()
    
    test1Spells = [5, 1, 3]
    test1Potions = [1, 2, 3, 4, 5]
    test2Spells = [3, 1, 2]
    test2Potions = [8, 5, 8]
    test3Spells = [1, 2, 3, 4, 5, 6, 7]
    test3Potions = [1, 2, 3, 4, 5, 6, 7]
    
    print(solution.successfulPairs(test1Spells, test1Potions, 7))
    print(solution.successfulPairs(test2Spells, test2Potions, 16))
    print(solution.successfulPairs(test3Spells, test3Potions, 25))
    
    