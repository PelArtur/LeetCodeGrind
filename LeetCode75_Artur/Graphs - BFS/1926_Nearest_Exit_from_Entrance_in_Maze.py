"""
https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List
from collections import deque

class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        queue = deque()
        queue.append((entrance[0], entrance[1]))
        maze[entrance[0]][entrance[1]] = '+'
        neighCoor = [[0, 1, 0, -1], [1, 0, -1, 0]]
        
        lenX = len(maze[0])
        lenY = len(maze)

        distance = 1
        
        while queue:
            elements_in_this_lvl = len(queue)
            
            for _ in range(elements_in_this_lvl):
                curr = queue.popleft()
                
                for i in range(4):
                    newY = curr[0] + neighCoor[0][i]
                    newX = curr[1] + neighCoor[1][i]
                    
                    if newX < 0 or newX >= lenX or newY < 0 or newY >= lenY:
                        continue
                    if maze[newY][newX] == '+':
                        continue
                    
                    if newX == 0 or newX == lenX - 1 or newY == 0 or newY == lenY - 1:
                        return distance
                    
                    maze[newY][newX] = '+'
                    queue.append((newY, newX))
            
            distance += 1
            
        return -1
    
        
if (__name__ == '__main__'):
    solution = Solution()
    
    test1Maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]
    test1Entrance = [1,2]
    test2Maze = [["+","+","+"],[".",".","."],["+","+","+"]]
    test2Entrance = [1,0]
    test3Maze = [[".","+"]]
    test3Entrance = [0,0]
    
    print(solution.nearestExit(test1Maze, test1Entrance))
    print(solution.nearestExit(test2Maze, test2Entrance))
    print(solution.nearestExit(test3Maze, test3Entrance))
