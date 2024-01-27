/*
 https://leetcode.com/problems/out-of-boundary-paths/description/?envType=daily-question&envId=2024-01-26
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
private:
    map<vector<int>, int> dp;
    int m;
    int n;

public:
    int dfs(int row, int col, int movesLeft)
    {
        if( row < 0 || row >= m || col < 0 || col >= n )
            return 1;
        if( !movesLeft )
            return 0;

        if( dp.find({row, col, movesLeft}) == dp.end() )
        {
            dp[{row, col, movesLeft}] = ((dfs(row - 1, col, movesLeft - 1) +
                                      dfs(row + 1, col, movesLeft - 1)) % 1000000007 +
                                      (dfs(row, col - 1, movesLeft - 1) +
                                      dfs(row, col + 1, movesLeft - 1)) % 1000000007) % 1000000007;
        }


        return dp[{row, col, movesLeft}];
    }


    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        this->m = m;
        this->n = n;
        dp.clear();

        return dfs(startRow, startColumn, maxMove);
    }
};


int main()
{
    Solution solution;

    cout << solution.findPaths(2, 2, 2, 0, 0) << endl;
    cout << solution.findPaths(1, 3, 3, 0, 1) << endl;
    cout << solution.findPaths(7, 6, 13, 0, 2) << endl;
}

/*
 Main idea:
 Up-to-down підхід, мапа dp зберігатиме кількість можливих шляхів
 від комірки i, j коли залишилось move ходів. Рекурсивно за допомогою
 dfs ідемо всіма шляхами за межі матриці, якщо вийшли з одного боку, то
 повертаємо 1, але якщо ходів на даний момент часу не залишилось, то повертаємо
 0.

 В іншому випадку кількість можливих ходів до комірки i, j на моменті, коли
 допустимо лишилось 5 можливих ходів, буде сумою можливих ходів усіх 4 сусідніх
 комірок на моменті, коли залишилось 4 ходи.

 Для уникнення повторних обрахунків і економлення часу з O(4^mn) до O(m*n*maxMoves),
 якщо значення поточної комірки в поточний момент часу уже є в мапі, то повертається
 її значення.

 dfs запускається з даної точки і з максимальним можливим значенням ходів.

 Часова складність алгоритму: O(m*n*maxMoves).
*/