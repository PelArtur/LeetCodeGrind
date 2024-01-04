"""
https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03
"""

from typing import List

class Solution(object):
    def numberOfBeams(self, bank: List[str]) -> int:
        """
        :type bank: List[str]
        :rtype: int
        """
        prevRow = 0
        beam = 0
        
        for row in bank:
            currRow = row.count('1')
            beam += prevRow * currRow
            prevRow = currRow if currRow else prevRow
            
        return beam


if (__name__ == '__main__'):
    solution = Solution()
    test = ["011001","000000","010100","001000"]
    print(solution.numberOfBeams(test))


"""
 Ідея описана в С++ файлі.
 В імплементації є відмінності, замість ще одного циклу
 із підрахункому одиниць в рядку використовується вбудований
 метод count()/.
"""
