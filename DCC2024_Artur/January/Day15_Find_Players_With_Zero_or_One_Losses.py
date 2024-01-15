"""
 https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15
"""
from typing import Optional, List
from collections import defaultdict

class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        losers = defaultdict(int)
        
        for match in matches:
            if not losers[match[0]]:
                losers[match[0]] = 0
            losers[match[1]] += 1
            
        zero_losts = []
        one_lost = []
        
        for loser in losers:
            if not losers[loser]:
                zero_losts.append(loser)
            elif losers[loser] == 1:
                one_lost.append(loser)
        
        return [sorted(zero_losts), sorted(one_lost)]

    
if __name__ == "__main__":
    test1 = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    test2 = [[2,3],[1,3],[5,4],[6,4]]
    
    print(Solution().findWinners(test1))
    print(Solution().findWinners(test2))


"""
 Main idea:
 
"""