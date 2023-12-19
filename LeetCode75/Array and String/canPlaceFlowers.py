from typing import List

class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        flowerbed = [0] + flowerbed + [0]
        total = 0
        i = 1
        while total != n and i != len(flowerbed)-1:
            if flowerbed[i] == 0 and 1 not in (flowerbed[i-1], flowerbed[i+1]):
                flowerbed[i] = 1
                total += 1
            i += 1
        return total == n
    
if __name__ == '__main__':
    print(Solution.canPlaceFlowers(1, flowerbed = [1,0,0,0,0,1], n = 2))
    print(Solution.canPlaceFlowers(1, flowerbed = [0,1,0,0,0,1], n = 2))
    print(Solution.canPlaceFlowers(1, flowerbed = [0,1,0,0,1,0], n = 2))
    print(Solution.canPlaceFlowers(1, flowerbed = [0,0,1,1,0,0], n = 2))
    print(Solution.canPlaceFlowers(1, flowerbed = [1,0,0,0,0,1], n = 2))
