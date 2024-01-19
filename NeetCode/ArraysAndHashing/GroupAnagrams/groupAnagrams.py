from collections import defaultdict
from typing import List, Dict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen_anagrams: Dict[str, list] = defaultdict(list)

        for string in strs:
            sorted_string: str = ''.join(sorted(string))
            seen_anagrams[sorted_string].append(string)

        return seen_anagrams.values()