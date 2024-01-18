/*
 https://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>>& grid)
    {
        map<const vector<int>, int> rows;

        int n = (int) grid.size();
        for(int i = 0; i < n; ++i)
            rows[grid[i]]++;

        auto col = vector<int>(n, 0);
        int res = 0;
        for(int j = 0; j < n; ++j)
        {
            for(int i = 0; i < n; ++i)
                col[i] = grid[i][j];

            if( rows.find(col) != rows.end() )
                res += rows[col];
        }

        return res;
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> test1 = {{3,2,1},{1,7,6},{2,7,7}};
    vector<vector<int>> test2 = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};

    cout << solution.equalPairs(test1) << endl;
    cout << solution.equalPairs(test2) << endl;
}

/*
 Main idea:
 Зробити мапу векторів. Де ключем буде рядок матриці, а значенням
 кількість такиз рядків.

 Спершу рахуємо кількість кожного рядка в матриці.
 Прохожимось і зчитуємо кожен стовпець і перевіряємо чи зчитаний
 масив є в мапі, якщо він присутній там, то до результату додаємо
 кількість таких рядків.

 Часова складність алгоритму: O(n^2)
*/