/*
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int n = (int) prices.size();
        vector<int> curr = {0, 0};
        vector<int> next = {0, 0};

        for(int i = n - 1; i >= 0; --i)
        {
            curr[1] = max(next[1] , next[0] - prices[i]);
            curr[0] = max(next[0] , prices[i] - fee + next[1]);
            next = curr;
        }

        return next[1];
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1,3,2,8,4,9};
    vector<int> test2 = {1,3,7,5,10,3};

    cout << solution.maxProfit(test1, 2) << endl;
    cout << solution.maxProfit(test2, 3) << endl;
}

/*
 Main idea:
 Є два масиви curr та next, які зберігають максимально можливе
 значення, якщо ми продаватимемо акцію(індекс 0) і якщо купуватимемо
 (індекс 1), відповідно для днів.

 Йдемо з кінця до початку і кожного разу перевіряємо чи нам вигідно
 купувати дану акцію, продавати, чи варто нічого не робити і записати
 значення з наступного дня.

 У кінці повертаємо значення з купівлі першої акції.

 Часова складність алгоритму: O(n)

 Гарне пояснення різних підходів до цієї задачі:
 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solutions/3668244/detailed-explanation-fastest-cakewalk-solution-for-everyone/?envType=study-plan-v2&envId=leetcode-75
*/