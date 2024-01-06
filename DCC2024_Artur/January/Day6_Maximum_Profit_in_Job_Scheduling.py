"""
https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03
"""

from typing import List

class Work:
    def __init__(self, startTime: int, endTime: int, profit: int) -> None:
        self.startTime = startTime
        self.endTime = endTime
        self.profit = profit

class Solution:
    def __init__(self) -> None:
        self.works = []
        self.sorted_end_time = []

    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        self.works = []
        
        for i in range(len(startTime)):
            self.works.append(Work(startTime[i], endTime[i], profit[i]))
            
        self.works.sort(key=lambda x: x.endTime)
        
        dp = []
        self.sorted_end_time = []
        
        for i in range(len(startTime)):
            dp.append(self.works[i].profit)
            self.sorted_end_time.append(self.works[i].endTime)
        
        for i in range(1, len(startTime)):
            lower_bound_ind = self.lower_bound(self.works[i].startTime)
            currprofit = 0
            if lower_bound_ind != -1:
                currprofit += dp[lower_bound_ind]
            
            dp[i] = max(dp[i-1], self.works[i].profit + currprofit)
            
        return dp[-1]
    
    def lower_bound(self, val: int):
        if self.sorted_end_time[0] > val:
            return -1
        l = 0
        r = len(self.sorted_end_time)
        
        while l < r:
            m = int(l + (r - l) / 2)
            
            if self.sorted_end_time[m] <= val:
                l = m + 1
            else:
                r = m
                
        return l - 1
        

if (__name__ == '__main__'):
    solution = Solution()
    test1 = [[1, 2, 3, 3], [3, 4, 5, 6], [50, 10, 40, 70]]
    test2 = [[1, 2, 3, 4, 6], [3, 5, 10, 6, 9], [20, 20, 100, 70, 60]]
    test3 = [[1, 1, 1], [2, 3, 4], [5, 6, 4]]
    test4 = [[4, 2, 4, 8, 2], [5, 5, 5, 10, 8], [1, 2, 8, 10, 4]]
    test5 = [[24,24,7,2,1,13,6,14,18,24], [27,27,20,7,14,22,20,24,19,27], [6,1,4,2,3,6,5,6,9,8]]
    
    print(solution.jobScheduling(test1[0], test1[1], test1[2]))
    print(solution.jobScheduling(test2[0], test2[1], test2[2]))
    print(solution.jobScheduling(test3[0], test3[1], test3[2]))
    print(solution.jobScheduling(test4[0], test4[1], test4[2]))
    print(solution.jobScheduling(test5[0], test5[1], test5[2]))

