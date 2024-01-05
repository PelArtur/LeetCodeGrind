/*
https://leetcode.com/problems/longest-increasing-subsequence/description/?envType=daily-question&envId=2024-01-05
*/

#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for(int idx = 0; idx < nums.size(); ++idx){
            for(int i = 0; i < idx; ++i){
                if(nums[i] < nums[idx] && dp[i] >= dp[idx]){
                    dp[idx] = 1 + dp[i];
                    result = max(result, dp[idx]);
                }
            }
        }
        return result;
    }
};


/*
 Main idea:

 Не найкращий розв'язок по складності O(n^2)

 Динаміка
 На кожному елементі перевіряємо всі попередні елементи, якщо вони менші.
 Якщо довжина найбільшої послідовності в конкретному елементі більша ніж
 поточна і попередній елемент є менший ніж наш, ми збільшуємо значення
 найбільшої послідовності на одиницю.

 Там є цікаві оптимальніші рішення, треба чекнути.
 */