"""
https://leetcode.com/problems/sort-characters-by-frequency/description/?envType=daily-question&envId=2024-02-07
"""

from typing import List
from collections import defaultdict

class Solution:
    def frequencySort(self, s: str) -> str:
        count = defaultdict(int)
        for char in s:
            count[char] += 1
            
        res = ''
        for char in sorted(count, key=lambda x : count[x], reverse=True):
            res += char * count[char]
            
        return res
            
        

if __name__ == '__main__':
    
    print(Solution().frequencySort("tree"))
    print(Solution().frequencySort("cccaaa"))
    print(Solution().frequencySort("Aabb"))
