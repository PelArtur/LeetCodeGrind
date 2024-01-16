/*
 https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/?envType=study-plan-v2&envId=leetcode-75
 */


class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>> possibleMoves;
        queue<int> movesDepth;

        vector<int> front;
        int depth;

        possibleMoves.push(entrance);
        movesDepth.push(0);

        while(!possibleMoves.empty()){
            front = possibleMoves.front();
            depth = movesDepth.front();
            possibleMoves.pop();
            movesDepth.pop();

            if(front != entrance && (front[0] == 0 || front[0] == maze.size() - 1 || front[1] == 0 || front[1] == maze[0].size() - 1)){
                return depth;
            }
            if(front[0] != 0 && maze[front[0] - 1][front[1]] == '.'){
                possibleMoves.push({front[0] - 1, front[1]});
                movesDepth.push(depth + 1);
                maze[front[0] - 1][front[1]] = '+';
            }
            if(front[0] != maze.size() - 1 && maze[front[0] + 1][front[1]] == '.'){
                possibleMoves.push({front[0] + 1, front[1]});
                movesDepth.push(depth + 1);
                maze[front[0] + 1][front[1]] = '+';
            }
            if(front[1] != maze[0].size() - 1 && maze[front[0]][front[1] + 1] == '.'){
                possibleMoves.push({front[0], front[1] + 1});
                movesDepth.push(depth + 1);
                maze[front[0]][front[1] + 1] = '+';
            }
            if(front[1] != 0 && maze[front[0]][front[1] - 1] == '.'){
                possibleMoves.push({front[0], front[1] - 1});
                movesDepth.push(depth + 1);
                maze[front[0]][front[1] - 1] = '+';
            }
        }

        return -1;
    }
};


/*
 Зберігаємо чергу всіх кімнат і відповідно чергу глибин

 Для кожної нової кімнати позначаємо її як + в лабіринті
 Пушимо всі доступні кімнати навколо неї в чергу
 Для кожної доступної кімнати пушимо поточну глибину + 1
 Таким чином для кожної кімнати ми будемо знати яка до неї
 глибина.
 Якщо кімната на краю лабіринту - повертаємо її глибину

 В іншому випадку повертаємо -1
 */