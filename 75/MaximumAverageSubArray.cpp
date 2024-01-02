/*
 https://leetcode.com/problems/maximum-average-subarray-i/?envType=study-plan-v2&envId=leetcode-75
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = 0;
        double tempResult = 0;
        int numsSize = nums.size();
        for(int i = 0; i < k; i ++){
            result += nums[i];
        }
        tempResult = result;
        for(int i = 1; i <= numsSize - k; i++){
            tempResult = tempResult - nums[i - 1] + nums[i + k - 1];
            if (tempResult > result){
                result = tempResult;
            }
        }
        return result/k;
    }
};

int main(){
    Solution solution;
    vector<int> input = {1,12,-5,-6,50,3};
    cout << solution.findMaxAverage(input, 4);
}