/*
 https://leetcode.com/problems/keys-and-rooms/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        auto visited = vector<int>(rooms.size(), 0);

        dfs(rooms, 0, visited);

        for(auto visit : visited)
            if(!visit)
                return false;

        return true;
    }

    void dfs(vector<vector<int>>& rooms, int vert, vector<int>& visited)
    {
        if(visited[vert])
            return;

        visited[vert] = 1;

        for(auto neigh : rooms[vert])
            if(!visited[neigh])
                dfs(rooms, neigh, visited);
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> test1 = {{1}, {2}, {3}, {}};
    vector<vector<int>> test2 = {{1, 3}, {3, 0, 1}, {2}, {0}};

    cout << solution.canVisitAllRooms(test1) << endl;
    cout << solution.canVisitAllRooms(test2) << endl;
}

/*
 Main idea:
 Стандартний dfs, отримуємо напрямлений граф, переданий як масив
 масивів, де за індекс і представляє вершину і, а масив за цим
 індексом представляє усі вершини, до яких можна потрапити з і.

 Запускаємо dfs, після чого перевіряємо, чи всі вершини були пройдені,
 якщо принаймні одна вершина не була відвідана, то повертається false,
 в іншому випадку повертається true.
*/