"""
https://leetcode.com/problems/minimum-window-substring/?envType=daily-question&envId=2024-02-04
"""

from typing import List
from collections import defaultdict

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        occurrence_t = defaultdict(int)
        occurrence_window = defaultdict(int)
        
        for char in t:
            occurrence_t[char] += 1
        
        unique_t = len(occurrence_t)
        unique_window = 0
        curr_Min = 999999999
        min_left = -1
        l = 0
        
        for r in range(len(s)):
            if unique_window != unique_t:
                occurrence_window[s[r]] += 1
                if occurrence_window[s[r]] == occurrence_t[s[r]]:
                    unique_window += 1
            
            if unique_window == unique_t:
                while unique_window == unique_t:
                    occurrence_window[s[l]] -= 1
                    if occurrence_window[s[l]] < occurrence_t[s[l]]:
                        unique_window -= 1
                    l += 1
                if (r - l + 1) < curr_Min:
                    curr_Min = r - l + 1
                    min_left = l - 1
        
        if min_left == -1:
            return ""
        
        return s[min_left:min_left + curr_Min + 1]

if __name__ == '__main__':
    
    print(Solution().minWindow("ADOBECODEBANC", "ABC"))
    print(Solution().minWindow("a", "a"))
    print(Solution().minWindow("a", "aa"))
