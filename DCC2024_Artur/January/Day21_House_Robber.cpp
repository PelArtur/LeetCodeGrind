/*
 https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if( nums.size() == 1)
            return nums[0];
        vector<int> dp = vector<int>(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < nums.size(); ++i)
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

        return dp.back();
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {2, 7, 9, 3, 1};
    vector<int> test3 = {2, 1, 1, 2};

    cout << solution.rob(test1) << endl;
    cout << solution.rob(test2) << endl;
    cout << solution.rob(test3) << endl;
}

/*
 Main idea:
 Динаміка, де і позиція відповідає максимальні сумі
 вкрадених грошей на і будинку.

 Перевіряємо чи нам вигідно
 грабувати дім і в сумі, яка була до дому і-2, чи
 не грабувати його та залишитись з сумою, яка була
 на попередньому будинку.

 Складність роботи O(n)
*/