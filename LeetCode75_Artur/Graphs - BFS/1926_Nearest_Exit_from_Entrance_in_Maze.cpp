/*
 https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
        {
            int availableExit = 0;

            for(auto & y : maze)
            {
                if ( y[0] == '.' )
                    availableExit++;
                if ( y[maze[0].size()-1] == '.' )
                    availableExit++;
            }

            for(int i = 0; i < maze[0].size(); ++i)
            {
                if( maze[0][i] == '.' )
                    availableExit++;
                if( maze[maze.size()-1][i] == '.' )
                    availableExit++;
            }

            if( !availableExit )
                return -1;

            auto distance = vector<vector<int>>(maze.size(), vector<int>(maze[0].size(), 0));
            vector<vector<int>> neighCoord = {{-1, 0, 1, 0}, {0, -1, 0, 1}};

            deque<pair<int, int>> q;
            q.emplace_back(entrance[0], entrance[1]);
            maze[entrance[0]][entrance[1]] = '+';

            pair<int, int> curr;
            while( !q.empty() )
            {
                curr = q.front();
                q.pop_front();

                for(int i = 0; i < 4; ++i)
                {
                    int newY = curr.first + neighCoord[0][i];
                    int newX = curr.second + neighCoord[1][i];

                    if( newX < 0 || newX >= maze[0].size() || newY < 0 || newY >= maze.size() )
                        continue;
                    if( maze[newY][newX] == '+' )
                        continue;

                    maze[newY][newX] = '+';
                    distance[newY][newX] = distance[curr.first][curr.second] + 1;
                    q.emplace_back(newY, newX);

                    if( newY == 0 || newY == maze.size() - 1 ||
                        newX == 0 || newX == maze[0].size() - 1 )
                        return distance[newY][newX];
                }
            }

            return -1;
        }
};


int main()
{
    Solution solution;

    vector<vector<char>> test1Maze = {{'+', '+', '.', '+'},
                                      {'.', '.', '.', '+'},
                                      {'+', '+', '+', '.'}};
    vector<int> test1Entrance = {1, 2};
    vector<vector<char>> test2Maze = {{'+', '+', '+'},
                                      {'.', '.', '.'},
                                      {'+', '+', '+'}};
    vector<int> test2Entrance = {1, 0};
    vector<vector<char>> test3Maze = {{'.', '+'}};
    vector<int> test3Entrance = {0, 0};

    cout << solution.nearestExit(test1Maze, test1Entrance) << endl;
    cout << solution.nearestExit(test2Maze, test2Entrance) << endl;
    cout << solution.nearestExit(test3Maze, test3Entrance) << endl;
}

/*
 Main idea:
 Спершу перевіряємо edge case, коли уся рамка лабіринту містить
 стіни, тобто вихожу немає взагалі.
 Дальше за допомогою BFS, починаючи з першої точки, шукаємо всі
 можливі ходи. Як індикатор відвіданої клітинки, заповняємо її
 стіною: "+", щоб не виділяти пам'ять на додатковий масив.
 У distance зберігаємо відстань до точки (x, y) починаючи з
 entrance.

 Якщо протягом bfs дійшли до комірки, яка знаходиться на краю
 лабіринту, тобто є виходом, то повертаємо її відстань через
 distance[y][x].

 Якщо процес BFS завершився і такої комірки не було знайдено, то
 повертаємо -1.

 Час роботи: O(mn), де m та n — розміри лабіринту.
*/