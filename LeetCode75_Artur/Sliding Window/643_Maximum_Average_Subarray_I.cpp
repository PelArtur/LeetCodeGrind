/*
https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        double currSum = 0;
        for(size_t i = 0; i < k; ++i)
            currSum += nums[i];

        double res = currSum;

        for(size_t j = k; j < nums.size(); ++j)
        {
            currSum = currSum - nums[j - k] + nums[j];
            res = max(currSum, res);
        }

        return res / k;
    }
};

int main()
{
    Solution solution;
    vector<int> test = {1, 12, -5, -6, 50, 3};
    int k = 4;

    cout << solution.findMaxAverage(test, k);
}

/*
 Main idea:
 Проходимось по стрічці і додаємо символи в результат, якщо символом не
 є ']'. Якщо трапився цей символ, то в тимчасову стрічку додаємо всі
 символи, до першого символа ']'. Тобто ми зчитали той текст, який
 необхідно продублювати.

 Дальше зчитуємо скільки раз необхідно продублювати даний текст. Оскільки
 число може бути більшим за десять, є змінна isDig, яка зберігає порядок
 числа(десяток, сотня тощо). Поки ми отримуємо це число ми збільшуємо його
 порядок та саме значення числа.

 Після того, як отримали всю необхідну інформацію: стрічку, яку необхідно
 повторити та скільки раз потрібно це зробити, додаємо результат у нашу
 стрічку, яка буде повернена.

 Цікавий розв'язок із рекурсією


 class Solution {
 public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos, s);
    }

    string helper(int& pos, string s) {
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            if(cur == '[') {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else {    // Normal characters
                word += cur;
            }
        }
        return word;
    }
 };

 Тут одне відкриття дужок [...] є однією ітерацією в рекурсії, якщо є вкладені
 дужки, то спершу запускається виклик рекурсивної функції до вкладених дужок, а
 потім лише в даних.
*/