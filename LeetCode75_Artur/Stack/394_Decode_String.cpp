/*
 https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    string decodeString(string s)
    {
        string res;
        size_t i = 0;
        while( i < s.size() )
        {
            if(s[i] == ']')
            {
                string temp;
                size_t j = res.size() - 1;
                while (res[j] != '[')
                {
                    temp.push_back(res[j--]);
                    res.pop_back();
                }
                res.pop_back();
                int isDig = 1;
                int rep = 0;
                while (j && isdigit(res[--j]))
                {
                    rep += (res[j] - '0') * isDig;
                    isDig *= 10;
                    res.pop_back();
                }

                for(int k = 0; k < rep; ++k)
                    for(int l = (int) temp.size() - 1; l >= 0; --l)
                        res.push_back(temp[l]);
            }
            else
                res.push_back(s[i]);

            i++;
        }

        return res;
    }
};


int main()
{
    Solution solution;

    string test1 = "3[a]2[bc]";
    string test2 = "3[a2[c]]";
    string test3 = "2[abc]3[cd]ef";
    string test4 = "100[leetcode]";

    cout << solution.decodeString(test1) << endl;
    cout << solution.decodeString(test2) << endl;
    cout << solution.decodeString(test3) << endl;
    cout << solution.decodeString(test4) << endl;
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