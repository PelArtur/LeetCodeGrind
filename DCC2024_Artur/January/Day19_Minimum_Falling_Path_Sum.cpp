/*
 https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = (int) matrix.size();
        auto dp = vector<vector<int>>(n, vector<int>(n, 0));
        for(int j = 0; j < n; ++j)
            dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; ++i)
        {
            dp[i][0] = matrix[i][0] + min(dp[i-1][0], dp[i-1][1]);
            dp[i][n-1] = matrix[i][n-1] + min(dp[i-1][n-1], dp[i-1][n-2]);

            for(int j = 1; j < n - 1; ++j)
                dp[i][j] = matrix[i][j] + min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]));
        }

        int minPath = INT_MAX;
        for(int j = 0; j < n; ++j)
            if( dp[n-1][j] < minPath )
                minPath = dp[n-1][j];

        return minPath;
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> test1 = {{2,1,3},{6,5,4},{7,8,9}};
    vector<vector<int>> test2 = {{-19,57},{-40,-5}};

    cout << solution.minFallingPathSum(test1) << endl;
    cout << solution.minFallingPathSum(test2) << endl;
}

/*
 Main idea:
 Створюємо масив динаміки такого ж розміру як матриця
 Перший рядок забиваємо тими ж значеннями, як у матриці

 dp[i][j] буде містити найкоротший шлях до [i][j] елемента
 матриці включно. Тому dp[i][j] буде сумою відподного значення
 в матриці та значення масиву dp із суміжних комірок, за умовою
 їх є три (row + 1, col - 1), (row + 1, col), або (row + 1, col + 1).

 Для крайній комірок(справа та зліва) рахуємо це значення окремо,
 оскільки в них лише 2 таких сусіда.

 У кінці шукаємо найменше значення з останнього рядка та повертаємо
 його.

 Часова складність алгоритму: O(n^2).

 Як вдосконалити алгоритм?
 Можна розмір додаткової пам'яті з O(n^2) зменшити до O(1), якщо всі
 значення зберігати саме в матриці, а не в додатковому для цього масиву.
*/