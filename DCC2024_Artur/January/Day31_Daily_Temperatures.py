"""
 https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31
"""
from typing import Optional, List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        stack = []    #(temperature value, ind)
        res = [0 for _ in range(len(temperatures))]
        
        for i in range(len(temperatures) - 1, -1, -1):
            while stack and stack[-1][0] <= temperatures[i]:
                stack.pop()
                
            if stack:
                res[i] = stack[-1][1] - i
            
            stack.append((temperatures[i], i))
            
        return res

    
if __name__ == "__main__":
    test1 = [73,74,75,71,69,72,76,73]
    test2 = [30,40,50,60]   
    test3 = [30,60,90]
    
    print(Solution().dailyTemperatures(test1))
    print(Solution().dailyTemperatures(test2))
    print(Solution().dailyTemperatures(test3))
