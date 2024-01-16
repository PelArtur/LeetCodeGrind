"""
 https://leetcode.com/problems/insert-delete-getrandom-o1/description/?envType=daily-question&envId=2024-01-16
"""
import random
from typing import Optional, List
from collections import defaultdict


class RandomizedSet:
    def __init__(self):
        self.elemInd = defaultdict(int)
        self.set = []
        self.size = 0
        
    def insert(self, val: int) -> bool:
        if val in self.elemInd:
            return False
        
        self.elemInd[val] = self.size
        self.set.append(val)
        self.size += 1
        return True
        
    def remove(self, val: int) -> bool:
        if val not in self.elemInd:
            return False
        
        removeInd = self.elemInd[val]
        self.set[removeInd] = self.set[-1]
        self.elemInd[self.set[removeInd]] = removeInd
        self.set.pop()
        self.elemInd.pop(val)
        self.size -= 1
        return True
        

    def getRandom(self) -> int:
        return self.set[random.randint(0, self.size - 1)]

    
if __name__ == "__main__":
    obj = RandomizedSet()
    print(obj.insert(1))
    print(obj.insert(2))
    print(obj.insert(3))
    print(obj.insert(4))
    print(obj.getRandom())
    print(obj.getRandom())
    print(obj.insert(2))
    print(obj.remove(2))
    print(obj.remove(2))
    print(obj.remove(4))
    print(obj.getRandom())
    print(obj.getRandom())


