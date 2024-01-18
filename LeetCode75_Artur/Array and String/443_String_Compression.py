"""
https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def compress(self, chars: List[str]) -> int:
        i = 0
        currCharInd = 0
        while i < len(chars):
            currChar = chars[i]
            chars[currCharInd] = currChar
            currCharInd += 1
            
            occurrence = 0
            while i < len(chars) and chars[i] == currChar:
                occurrence += 1
                i += 1
            
            if occurrence > 1:
                for num in str(occurrence):
                    chars[currCharInd] = num
                    currCharInd += 1
        
        return currCharInd
    
if (__name__ == '__main__'):
    solution = Solution()

    test1 = ["a","a","b","b","c","c","c"]
    test2 = ["a"]
    test3 = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
    
    print(solution.compress(test1))
    print(solution.compress(test2))
    print(solution.compress(test3))
    