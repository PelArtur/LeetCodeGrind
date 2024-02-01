/*
 https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i += 3)
        {
            if (nums[i + 2] - nums[i] <= k)
                return {};
            res.push_back({nums[i], nums[i+1], nums[i+2]});
        }

        return res;
    }
};


int main()
{
    vector<int> test1 = {1,3,4,8,7,9,3,5,1};
    vector<int> test2 = {1,3,3,2,7,3};

    Solution().divideArray(test1, 2);
    Solution().divideArray(test2, 3);
}

/*
 Main idea:
 Сортуємо масив у неспадному порядку. Оскільки нам дано, що
 розмір масиву є 3n, то немає потреби перевіряти чи не вийде
 так, що якись з під масивів не буде мати розмір 3.
 У циклі з кроком три перевіряємо чи різниця найбільшого та
 найменшого елемента в потенційному підмасиві є більшою
 за k, тобто arr[i+2] - arr[i] > 3. Якщо ця умова правдива, то
 до результату додаємо масив з і, і + 1 та і + 2 елементів.

 Якщо цикл дійшов до кінця та умова вище ніразу не виконалась, то
 повертається результат.
*/