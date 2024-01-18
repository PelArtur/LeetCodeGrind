"""
https://leetcode.com/problems/smallest-number-in-infinite-set/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List

class SmallestInfiniteSet:

    def __init__(self):
        self.set = set()
        self.smallest = 1
        
    def popSmallest(self) -> int:
        if self.set:
            smallest = min(self.set)
            self.set.remove(smallest)
            return smallest
        else:
            smallest = self.smallest
            self.smallest += 1
            return smallest
        
    def addBack(self, num: int) -> None:
        if num < self.smallest:
            self.set.add(num)
    
        
if (__name__ == '__main__'):
    obj = SmallestInfiniteSet()
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    
    obj.addBack(5)
    obj.addBack(2)
    obj.addBack(6)
    obj.addBack(1)
    obj.addBack(100)
    
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    print(obj.popSmallest())
    
    
"""
Тут реалізована ідея з цього розв'язку:
https://leetcode.com/problems/smallest-number-in-infinite-set/solutions/3452136/image-explanation-fastest-easiest-with-dry-run-c-java-python/?envType=study-plan-v2&envId=leetcode-75

Також цікава особливість, що в С++ сет є одразу посортованим
"""
