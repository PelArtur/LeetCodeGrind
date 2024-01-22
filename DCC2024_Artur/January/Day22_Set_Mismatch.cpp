/*
 https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n = (int) nums.size();
        unordered_map<int, int> occurrence;

        for(auto num : nums)
            occurrence[num]++;

        vector<int> res = {-1, -1};
        for(int i = 1; i <= n; ++i)
        {
            if (occurrence[i] > 1)
                res[0] = i;
            if( !occurrence[i] )
                res[1] = i;
        }

        return res;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1, 2, 2, 4};
    vector<int> test2 = {1, 1};

    solution.findErrorNums(test1);
    solution.findErrorNums(test2);
}

/*
 Main idea:
 Рахуємо кількість входжень кожної літери в масиві і записуємо
 це значення в мапу:
 - ключ: число;
 - значення: кількість входжень цього числа;

 Після чого проходимось циклом від 1 до n(довжини масиву), і перевірями
 чи число i зустрічається більше ніж один раз, якщо так, то записуємо
 його в перше значення результату, а якщо це число не зустрічалось, то в
 друге.

 Часова складність роботи алгоритму: O(n)
*/