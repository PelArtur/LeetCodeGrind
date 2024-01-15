/*
 https://leetcode.com/problems/increasing-triplet-subsequence/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int>& nums)
    {
        int max = INT_MIN;
        int secondMax = INT_MIN;

        for(int i = (int) nums.size() - 1; i >= 0; --i)
        {
            if( nums[i] >= max )
                max = nums[i];
            else if( nums[i] >= secondMax )
                secondMax = nums[i];
            else
                return true;
        }

        return false;
    }
};



int main()
{
    Solution solution;

    vector<int> test1 = {1, 2, 3, 4, 5};
    vector<int> test2 = {5, 4, 3, 2, 1};
    vector<int> test3 = {2, 1, 5, 0, 4, 6};

    cout << solution.increasingTriplet(test1) << endl;
    cout << solution.increasingTriplet(test2) << endl;
    cout << solution.increasingTriplet(test3) << endl;
}

/*
 Main idea:
 Шукаємо максимальне та друге максимальне число масиву з кінця.
 Якщо число більше за максимальне, то записуємо його як максимум,
 якщо число є меншим за маскимум, але більшим чи рівним за другий
 максимум, то записуємо його в другий максимум, якщо ж число є меншим
 за два максимуми, то знайшли зростаючу підпослідовність і вертаємо
 true.

 Часова складність алгоритму: O(n).
*/