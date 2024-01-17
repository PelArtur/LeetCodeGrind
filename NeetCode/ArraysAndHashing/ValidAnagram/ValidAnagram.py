class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if(len(s) != len(t)):
            return False
        letterOccurence = [0 for i in range(26)]
        for idx in range(len(s)):
            letterOccurence[ord(s[idx]) - 97] += 1
            letterOccurence[ord(t[idx]) - 97] -= 1

        for value in letterOccurence:
            if value != 0:
                return False

        return True
