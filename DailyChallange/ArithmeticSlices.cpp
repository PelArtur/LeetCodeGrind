/*
 https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/?envType=daily-question&envId=2024-01-07
 */

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int factorial(int num){
        int result = 1;
        for(int i = 1; i < num; i++){
            result *= i;
        }
        return result;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int result = 0;
        int lengthOfSequence = 0;
        map<int, pair<int,int>> sequenceLength;
        map<int, int> copies;
        for(int number : nums){
            for(auto element : sequenceLength){
                if(number - element.second.second == element.first){
                    sequenceLength[element.first].second = number;
                } else {
                    sequenceLength[number - element.second.second].second = number;
                    sequenceLength[number - element.second.second].first = element.second.second;
                }
            }
            if(sequenceLength[number].first == 0){
                sequenceLength[number].first = number;
                sequenceLength[number].second = number;
            } else {
                if(copies[number] == 0){
                    copies[number] = 2;
                } else {
                    copies[number]++;
                }
            }
        }

        for(auto element : sequenceLength){
            lengthOfSequence = element.second.first/element.first;
            if(lengthOfSequence >= 3) {
                result += ((lengthOfSequence - 1) * (lengthOfSequence - 2)) / 2;
            }
        }

        return result;
    }
};


int main(){
    vector<int> input = {2,4,6,8,10};
    map<int, pair<int, int>> hehe;
    cout << Solution().numberOfArithmeticSlices(input);
    return 0;
}