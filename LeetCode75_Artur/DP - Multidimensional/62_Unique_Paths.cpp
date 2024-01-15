/*
 https://leetcode.com/problems/unique-paths/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        auto dp = vector<vector<int>>(m, vector<int>(n, 1));

        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m-1][n-1];
    }
};


int main()
{
    Solution solution;
    vector<int> test1 = {3, 2};
    vector<int> test2 = {3, 7};
    vector<int> test3 = {1, 1};

    cout << solution.uniquePaths(test1[0], test1[1]) << endl;
    cout << solution.uniquePaths(test2[0], test2[1]) << endl;
    cout << solution.uniquePaths(test3[0], test3[1]) << endl;
}

/*
 Main idea:
 Динаміка, забиваємо матрицю m на n одиницями.
 Рухаємось з індексів 1, 1. Кількість можливих шляхів,
 щоб потрапити в точкі x, y є рівною сумі можливих ходів
 через верхню клітинку та лів, тому динаміка виглядатиме так:
 dp[x][y] = dp[x-1][y] + dp[x][y-1]

 Час виконання програми O(m * n)

 Є більш оптимальний варіант як по часу, так і по пам'яті, обраховуючи
 це математично через комбінаторику, посилання на це рішення:
 https://leetcode.com/problems/unique-paths/solutions/1581998/c-python-5-simple-solutions-w-explanation-optimization-from-brute-force-to-dp-to-math/?envType=study-plan-v2&envId=leetcode-75
*/