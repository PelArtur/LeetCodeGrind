"""
https://leetcode.com/problems/sequential-digits/?envType=daily-question&envId=2024-02-02
"""

from typing import List

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        nums = '123456789'
        res = []
        
        for sliding_window in range(1, 10):
            for i in range(10 - sliding_window):
                num = int(nums[i:i + sliding_window])
                if num < low:
                    continue
                if num > high:
                    break
                res.append(num)
                
        return res
        

if __name__ == '__main__':
    
    print(Solution().sequentialDigits(100, 300))
    print(Solution().sequentialDigits(1000, 13000))
