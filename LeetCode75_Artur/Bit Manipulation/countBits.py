class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = [0 for _ in range(n+1)]
        for i in range(1, n + 1):
            res[i] = res[i >> 1] + (i & 1)
        
        return res
        