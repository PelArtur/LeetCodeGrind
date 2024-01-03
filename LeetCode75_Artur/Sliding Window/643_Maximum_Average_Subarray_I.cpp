/*
https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double currSum = 0;
        for(size_t i = 0; i < k; ++i)
            currSum += nums[i];

        double res = currSum;

        for(size_t j = k; j < nums.size(); ++j)
        {
            currSum = currSum - nums[j - k] + nums[j];
            res = max(currSum, res);
        }

        return res / k;
    }
};

int main()
{
    Solution solution;
    vector<int> test = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << solution.findMaxAverage(test, k);
}