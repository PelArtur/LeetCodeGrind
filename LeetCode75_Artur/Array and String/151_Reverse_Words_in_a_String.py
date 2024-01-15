"""
https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def reverseWords(self, s: str) -> str:
        splited = s.split()
        res = splited[-1]
        
        for i in range(len(splited) - 2, -1, -1):
            res += ' ' + splited[i]
        
        return res
    
if (__name__ == '__main__'):
    solution = Solution()
    
    test1Spells = [5, 1, 3]
    test1 = "the sky is blue"
    test2 = "  hello world  "
    test3 = "a good   example"
    
    print(solution.reverseWords(test1))
    print(solution.reverseWords(test2))
    print(solution.reverseWords(test3))
    