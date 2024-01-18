"""
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        currVowels = 0
        vowels = "aeiuo"
        for i in range(k):
            if s[i] in vowels:
                currVowels += 1
        
        maxVowels = currVowels
        for i in range(k, len(s)):
            if s[i] in vowels:
                currVowels += 1
            if s[i - k] in vowels:
                currVowels -= 1
            if currVowels > maxVowels:
                maxVowels = currVowels
                
        return maxVowels
    
if __name__ == '__main__':
    solution = Solution()
    
    test1 = "abciiidef"
    test2 = "aeiou"
    test3 = "leetcode"
    
    print(solution.maxVowels(test1, 3))
    print(solution.maxVowels(test1, 2))
    print(solution.maxVowels(test1, 2))

    