"""
https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06
"""

from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for word in strs:
            anagrams[tuple(sorted(word))].append(word)
            
        return list(anagrams.values())
        

if __name__ == '__main__':
    
    print(Solution().groupAnagrams(["eat","tea","tan","ate","nat","bat"]))
    print(Solution().groupAnagrams([""]))
    print(Solution().groupAnagrams(["a"]))
