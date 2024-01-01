from typing import List

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if not s:
            return True
        for chr in t:
            if chr == s[0]:
                if len(s) == 1:
                    return True
                s = s[1:]
        return False

print(Solution.isSubsequence(0, s = "abc", t = "ahbgdc"))
