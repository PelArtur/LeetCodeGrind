/*
https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> static findMatrix(vector<int>& nums) {
        int maxValue = 0;
        vector<int> uniqueNumbers;
        map<int, int> numbers;

        for(int number : nums){
            if (numbers[number] == 0){
                uniqueNumbers.push_back(number);
            }
            ++numbers[number];
            maxValue = max(numbers[number], maxValue);
        }
        vector<vector<int>> result(maxValue);

        for(int idx = 0; idx < maxValue; idx++){
            for(int number : uniqueNumbers){
                if(numbers[number] != 0){
                    --numbers[number];
                    result[idx].push_back(number);
                }
            }
        }

    return result;
    }
};

int main(){
    vector<int> input = {1,3,4,1,2,3,1};
    vector<vector<int>> result = Solution().findMatrix(input);
    for(int vectorNum = 0; vectorNum < result.size(); ++vectorNum){
        for(int insVecSize = 0; insVecSize < result[vectorNum].size(); ++insVecSize){
            cout << result[vectorNum][insVecSize] << " ";
        }
        cout << endl;
    }
}