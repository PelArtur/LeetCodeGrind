from typing import List

class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        flag = max(candies)
        for i in range(len(candies)):
            if candies[i] + extraCandies >= flag:
                candies[i] = True
            else:
                candies[i] = False
        return candies
    
print(Solution.kidsWithCandies(1, candies = [12,1,12], extraCandies = 10))