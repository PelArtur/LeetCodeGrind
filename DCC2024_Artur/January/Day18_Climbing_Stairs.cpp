/*
 https://leetcode.com/problems/climbing-stairs/description/?envType=daily-question&envId=2024-01-18
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if( n == 1 )
            return 1;
        auto dp = vector<int>(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; ++i)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n-1];
    }
};


int main()
{
    Solution solution;

    int test1 = 2;
    int test2 = 3;
    int test3 = 10;

    cout << solution.climbStairs(test1) << endl;
    cout << solution.climbStairs(test2) << endl;
    cout << solution.climbStairs(test3) << endl;
}

/*
 Main idea:
 Динаміка, у масиві за індексом і зберігається кількість
 можливих ходів на і + 1 сходинку.
 На і сходинку ми можемо потрапити або з і-1, або з і-2
 сходинки, тому загальна кількість можливих варіантів на
 неї потрапити буде сума dp[i-1], dp[i-2]

 Часова складність алгоритму O(n).

 Як зробити краще?
 Не виділяти масив розміром n, а зробити дві змінні, які
 відповідатимуть за і-1 та і-2 сходинку.
*/