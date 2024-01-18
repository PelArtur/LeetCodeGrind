/*
 https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int tribonacci(int n)
    {
        if( n == 0 )
            return 0;
        else if( n <= 2 )
            return 1;

        auto dp = vector<int>(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for(int i = 3; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

        return dp[n];
    }
};


int main()
{
    Solution solution;

    cout << solution.tribonacci(4) << endl;
    cout << solution.tribonacci(7) << endl;
    cout << solution.tribonacci(10) << endl;
    cout << solution.tribonacci(15) << endl;
    cout << solution.tribonacci(20) << endl;
    cout << solution.tribonacci(25) << endl;
}

/*
 Main idea:
 Динаміка, ідентична із задачею числами Фібоначчі,
 тільки цього разу додаються 3 попередні числа, а не
 2.

 Складність алгоритму: O(n)
*/