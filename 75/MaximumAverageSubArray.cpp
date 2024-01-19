/*
 https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int result = 0;
        int tempResult = 0;
        for(int i = 0; i < k; i ++){
            tempResult += nums[i];
        }
        result = tempResult;
        for(int i = k; i < nums.size(); i++){
            tempResult += nums[i] - nums[i - k];
            result = max(tempResult, result);
        }
        return static_cast<double>(result) / k;
    }
};

int main(){
    Solution solution;
    vector<int> input = {6};
    cout << solution.findMaxAverage(input, 1);
}