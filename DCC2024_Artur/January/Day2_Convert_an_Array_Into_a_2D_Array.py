class Solution(object):
    def findMatrix(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        map = dict()
        max = 0
        
        for num in nums:
            if num not in map:
                map[num] = 0
    
            map[num] += 1
            max = map[num] if map[num] > max else max
        
        res = [[] for _ in range(max)]
        
        for val in map:
            for i in range(map[val]):
                res[i].append(val)
                
        return res
