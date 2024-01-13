from typing import List

class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        curr_att, higher_att= 0, 0
        for att in gain:
            curr_att += att
            if curr_att > higher_att:
                higher_att = curr_att
        return higher_att
    
print(Solution.largestAltitude(1, [-4,-3,-2,-1,4,3,2]))
