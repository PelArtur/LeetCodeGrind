"""
https://leetcode.com/problems/implement-queue-using-stacks/?envType=daily-question&envId=2024-01-29
"""

from typing import Optional, List

class MyQueue:
    def __init__(self):
        self.queueHelper = list()
        self.queue = list()

    def push(self, x: int) -> None:
        self.queueHelper.append(x)

    def pop(self) -> int:
        if not self.queue:
            self.fillQueue()
        
        return self.queue.pop()
        
    def peek(self) -> int:
        if not self.queue:
            self.fillQueue()
        
        return self.queue[-1]

    def empty(self) -> bool:
        return not self.queue and not self.queueHelper
        
    def fillQueue(self):
        while self.queueHelper:
            self.queue.append(self.queueHelper.pop())
        
    
if __name__ == '__main__':
    obj = MyQueue()
    
    obj.push(1)
    obj.push(2)
    print(obj.peek())
    print(obj.pop())
    print(obj.empty())
