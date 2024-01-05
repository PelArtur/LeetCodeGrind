"""
https://leetcode.com/problems/keys-and-rooms/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import List


class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        visited = [0 for _ in range(len(rooms))]
        
        dfs(rooms, visited, 0)
        
        for elem in visited:
            if not elem:
                return False
        
        return True
        
        
def dfs(rooms: List[List[int]], visited: List[int], vert: int) -> None:
    if visited[vert]:
        return
    
    visited[vert] = 1
    
    for neigh in rooms[vert]:
        if not visited[neigh]:
            dfs(rooms, visited, vert)
        



if __name__ == "__main__":
    test1 = [[1], [2], [3], []]
    test2 = [[1, 3], [3, 0, 1], [2], [0]]
    
    print(Solution().canVisitAllRooms(test1))    
    print(Solution().canVisitAllRooms(test2))    


"""

"""