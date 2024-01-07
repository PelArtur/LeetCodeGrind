/*
 https://leetcode.com/problems/arithmetic-slices-ii-subsequence/?envType=daily-question&envId=2024-01-07
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        auto dp = vector<unordered_map<int, int>>(nums.size(), unordered_map<int, int>());
        int res = 0;
        for(int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                long long diff = (long long) nums[i] - nums[j];

                if(diff > INT_MAX || diff < INT_MIN)
                    continue;

                res += dp[j][(int) diff];

                dp[i][(int) diff] += dp[j][(int) diff] + 1;
            }
        }
        return res;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {2, 4, 6, 8, 10};
    vector<int> test2 = {7, 7, 7, 7, 7};
    vector<int> test3 = {2, 2, 3, 4};

    cout << solution.numberOfArithmeticSlices(test1) << endl;
    cout << solution.numberOfArithmeticSlices(test2) << endl;
    cout << solution.numberOfArithmeticSlices(test3) << endl;

    return 0;
}

/*
 Main idea:
 Створяємо dp масив, де елемент за індексом і є словником, у якому ключем
 є різниця між числом nums[i] та числами nums[j] де j < i. А значенням є
 довжина підпослідовності цих різниць.

 Ітеруємось за всіма елементами, починаючи з індекса і, і перевіряємо різниці
 між цим числом та всіма числами, які йдуть до нього. До результату додаємо довжину
 підмножини числа nums[j] з рідницею nums[i] - nums[j], оскільки довжини йдуть від
 0, то числа додаватимуться від 1, коли попереднє число має підмножину довжиною в
 2, а з нашим числом nums[i] матиме довжину 3, що підпадає умові. Тальше в dp для
 індексу і та даної різниці додаємо значення довжини попереднього числа + 1.

 Чому даний розв'язок коректний?

 Якщо ми маємо довжину підмножини 3, то можливих варіантів їх перестановок буде 1,
 Якщо розмір 4: [2, 4, 6, 8], то перестановок буде 3: [2, 4, 6], [4, 6, 8] та [2, 4, 6, 8].
 Якщо розмір 5: то перестановок 6(приклад даний в умові задачі на сайті, приклад [2, 6, 10],
 не підходить під цей патерн, бо тут різниця 4, у всіх інших 2).
 Тобто бачимо таку закономірність:

 n = 3,   3: 1
 n = 4,   3: 2, 4: 1
 n = 5,   3: 3, 4: 2, 5: 1
 n = 6,   3: 4, 4: 3, 5: 2, 6: 1

 Де ключ це розмір підпослідовності, послідовності розміром n, а значення це кількість можливих
 підпослідовностей з таким розміром. Як ми бачимо, зі збільшенням n, усі розміри менших підпослідовностей
 збільшується на 1, або ж загальна кількість можливих підпослідовностей збільшується на n-2.

 Складність роботи алгоритму: O(n^2)
*/
