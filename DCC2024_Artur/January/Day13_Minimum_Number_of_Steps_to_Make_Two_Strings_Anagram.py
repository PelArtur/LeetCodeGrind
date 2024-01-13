"""
https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
"""

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        lettersS = [0 for _ in range(26)]
        lettersT = [0 for _ in range(26)]
        
        for char in s:
            lettersS[ord(char) - ord('a')] += 1

        for char in t:
            lettersT[ord(char) - ord('a')] += 1
            
        steps = 0
        for i in range(26):
            if lettersS[i] - lettersT[i] > 0:
                steps += lettersS[i] - lettersT[i]
                
        return steps

if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = ["bab", "aba"]
    test2 = ["leetcode", "practice"]
    test3 = ["anagram", "mangaar"]
    
    
    print(solution.minSteps(test1[0], test1[1]))
    print(solution.minSteps(test2[0], test2[1]))
    print(solution.minSteps(test3[0], test3[1]))
