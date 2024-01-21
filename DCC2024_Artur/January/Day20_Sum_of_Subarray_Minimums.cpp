/*
 https://leetcode.com/problems/sum-of-subarray-minimums/?envType=daily-question&envId=2024-01-20
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        vector<int> stack;
        int mod = 1000000007;
        int res = 0;

        int ind, left, right;
        for(int i = 0; i < arr.size(); ++i)
        {
            while( !stack.empty() && arr[i] < arr[stack.back()] )
            {
                ind = stack.back();
                stack.pop_back();
                if( !stack.empty() )
                    left = ind - stack.back();
                else
                    left = ind + 1;
                right = i - ind;
                res = (res + left * right * arr[ind]) % mod;
            }
            stack.push_back(i);
        }

        for(int j = 0; j < stack.size(); ++j)
        {
            left = j > 0 ? stack[j] - stack[j - 1] : stack[j] + 1;
            right = (int) arr.size() - stack[j];
            res = (res + left * right * arr[stack[j]]) % mod;
        }

        return res;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {3,1,2,4};
    vector<int> test2 = {11,81,94,43,3};

    cout << solution.sumSubarrayMins(test1) << endl;
    cout << solution.sumSubarrayMins(test2) << endl;
}

/*
 Main idea:

*/