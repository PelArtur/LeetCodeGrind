/*
 https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = (int) nums.size();
        auto left = vector<int>(nums.size(), 1);
        auto right = vector<int>(nums.size(), 1);
        auto res = vector<int>(nums.size(), 1);

        for(int i = 1; i < n; ++i)
            left[i] = left[i-1] * nums[i-1];

        for(int j = n - 2; j >= 0; --j)
            right[j] = right[j + 1] * nums[j + 1];


        for(int k = 0; k < n; ++k)
            res[k] = left[k] * right[k];

        return res;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1,2,3,4};
    vector<int> test2 = {-1,1,0,-3,3};

    solution.productExceptSelf(test1);
    solution.productExceptSelf(test2);

}

/*
 Main idea:
 Рахуємо префікс та суфікс, тобто всі множення зліва та справа
 від і елементу, не включно з ним.
 Тоді до результату res[i] це буде множення правої і лівої частини
 масиву, тобто left[i] та right[i]

 Часова складність алгоритму: O(n).

 Кращий розв'язок з O(1) додатковою пам'ятю:

 class Solution {
 public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i = 0, suf = 1, pre = 1, n = size(nums); i < n; i++) {
            ans[i] *= pre;             // similar to prefix product being calculated in 1st loop of previous solution
            pre *= nums[i];
            ans[n-1-i] *= suf;         // similar to suffix product being calculated in 2nd loop of previous solution
            suf *= nums[n-1-i];
        }
        return ans;
    }
 };

 Тут операції префікса і суфікса зберігаються в змінних, тому виділяти
 додаткові масиви не є необхідно і значення одразу записуються в масив
 результату.
*/