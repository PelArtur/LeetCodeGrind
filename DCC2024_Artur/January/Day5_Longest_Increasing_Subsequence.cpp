/*
 https://leetcode.com/problems/longest-increasing-subsequence/?envType=daily-question&envId=2024-01-05
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int numsLen = (int) nums.size();
        auto dp = vector<int>(numsLen, 1);

        for(int i = numsLen - 1; i >= 0; --i)
            for(int j = i + 1; j < numsLen; ++j)
                if(nums[i] < nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);

        int maxLen = 0;
        for(auto len : dp)
            maxLen = max(maxLen, len);

        return maxLen;
    }
};

int main()
{
    Solution solution;

    vector<int> test1 = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> test2 = {0, 1, 0, 3, 2, 3};
    vector<int> test3 = {7, 7, 7, 7, 7, 7, 7};

    cout << solution.lengthOfLIS(test1) << endl;
    cout << solution.lengthOfLIS(test2) << endl;
    cout << solution.lengthOfLIS(test3) << endl;
}

/*
 Main idea: O(n^2), динаміка

 Створюємо dp масив, який за і індексом зберігатиме максимально
 маожливу довжину масиву, якщо починати з і елементу масиву nums.
 Забиваємо масив dp одиницями, оскільки вже саме число утворює множину
 розміром один.

 У циклі проходимось з останнього елементу. На і ітерації йдемо з і+1 до
 n-1 елемента(індекс j), якщо елемент за індексом j є строго більшим за
 елемент за індексом і, то в dp[i] = max(dp[i], 1 + dp[j]), тобто ми
 перевіряємо чи поточна найдовша множина починаючи з і елементу є більшою
 за найдовшу множину починаючи з j елемента, якщо до неї додамо і елемент.

 Повертаємо максимальний елемент масиву dp.

 Загальна кількість ітерацій є рівною n(n-1)/2, або ж O(n^2)

 https://www.youtube.com/watch?v=6WjnRyYLmM4&ab_channel=SpectralCollective
*/