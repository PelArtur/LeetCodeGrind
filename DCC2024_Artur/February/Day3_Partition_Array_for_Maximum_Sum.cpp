/*
 https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        vector<int> dp = vector<int>(arr.size(), 0);
        dp[0] = arr[0];

        int currMax = arr[0];
        for(int i = 1; i < k; ++i)
        {
            currMax = max(currMax, arr[i]);
            dp[i] = currMax * (i + 1);
        }

        for(int i = k; i < arr.size(); ++i)
        {
            currMax = arr[i];
            for(int j = i; j > i - k; --j)
            {
                currMax = max(currMax, arr[j]);
                dp[i] = max(dp[i], currMax * (i - j + 1) + dp[j-1]);
            }
        }

        return dp.back();
    }
};


int main()
{
    vector<int> test1 = {1,15,7,9,2,5,10};
    vector<int> test2 = {1,4,1,5,7,3,6,1,9,9,3};
    vector<int> test3 = {1};


    cout << Solution().maxSumAfterPartitioning(test1, 3) << endl;
    cout << Solution().maxSumAfterPartitioning(test2, 4) << endl;
    cout << Solution().maxSumAfterPartitioning(test3, 1) << endl;
}

/*
 Main idea:
 Пояснення з гарною візуалізацією цього алгоритму
 https://leetcode.com/problems/partition-array-for-maximum-sum/solutions/1621079/python-easy-dp-with-visualization-and-examples/?envType=daily-question&envId=2024-02-03

 Часова складість алгоритму: O(nk)
*/