"""
https://leetcode.com/problems/determine-if-string-halves-are-alike/?envType=daily-question&envId=2024-01-12
"""

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        return sum(letter in "aeiou" for letter in s[:len(s)//2].lower()) == sum(letter in "aeiou" for letter in s[len(s)//2:].lower())


if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = "book"
    test2 = "textbook"
    
    print(solution.halvesAreAlike(test1))
    print(solution.halvesAreAlike(test2))
