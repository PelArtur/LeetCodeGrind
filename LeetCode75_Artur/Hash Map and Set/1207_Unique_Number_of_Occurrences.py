"""
 https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=study-plan-v2&envId=leetcode-75
"""
from typing import Optional, List
from collections import defaultdict

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        occurrences = defaultdict(int)
        occurrencesAppear = defaultdict(bool)
        
        for num in arr:
            occurrences[num] += 1
        
        for occurr in occurrences:
            if occurrencesAppear[occurrences[occurr]]:
                return False
            occurrencesAppear[occurrences[occurr]] = True
            
        return True

    
if __name__ == "__main__":
    test1 = [1,2,2,1,1,3]
    test2 = [1,2]
    test3 = [-3,0,1,-3,1,1,1,-3,10,0]
    
    print(Solution().uniqueOccurrences(test1))
    print(Solution().uniqueOccurrences(test2))
    print(Solution().uniqueOccurrences(test3))
