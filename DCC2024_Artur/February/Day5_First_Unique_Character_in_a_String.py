"""
https://leetcode.com/problems/first-unique-character-in-a-string/description/?envType=daily-question&envId=2024-02-05
"""

from typing import List
from collections import defaultdict

class Solution:
    def firstUniqChar(self, s: str) -> int:
        indexes = [s.index(x) for x in set(s) if s.count(x) == 1]
        return -1 if not indexes else min(indexes)
        

if __name__ == '__main__':
    
    print(Solution().firstUniqChar("leetcode"))
    print(Solution().firstUniqChar("loveleetcode"))
    print(Solution().firstUniqChar("aabb"))
