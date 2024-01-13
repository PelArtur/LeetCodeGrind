"""
https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
"""

class Solution:
    def predictPartyVictory(self, senate: str) -> str:
        bannedValue = 0
        i = 0
        while i < len(senate):
            if senate[i] == 'R':
                if bannedValue < 0:
                    senate += 'D'
                bannedValue += 1
            else:
                if bannedValue > 0:
                    senate += 'R'
                bannedValue -= 1
            i += 1
        
        return "Radiant" if bannedValue > 0 else "Dire"

if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = "RD"
    test2 = "RDD"
    
    print(solution.predictPartyVictory(test1))
    print(solution.predictPartyVictory(test2))
