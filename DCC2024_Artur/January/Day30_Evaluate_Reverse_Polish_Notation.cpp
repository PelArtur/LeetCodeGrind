/*
 https://leetcode.com/problems/evaluate-reverse-polish-notation/?envType=daily-question&envId=2024-01-30
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
private:
    stack<int> stack;

    int computeVal(int num1, int num2, string operation)
    {
        if( operation == "/" )
            return num1 / num2;
        else if( operation == "*" )
            return num1 * num2;
        else if( operation == "+" )
            return num1 + num2;

        return num1 - num2;
    }

public:
    int evalRPN(vector<string>& tokens)
    {
        for(auto token : tokens)
        {
            if( token[0] <= '/' && token.size() == 1 )
            {
                int val1 = stack.top(); stack.pop();
                int val2 = stack.top(); stack.pop();

                stack.push(computeVal(val2, val1, token));
            }
            else
                stack.push(stoi(token));
        }

        return stack.top();
    }
};


int main()
{
    vector<string> test1 = {"2","1","+","3","*"};
    vector<string> test2 = {"4","13","5","/","+"};
    vector<string> test3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

    //cout << Solution().evalRPN(test1) << endl;
    //cout << Solution().evalRPN(test2) << endl;
    cout << Solution().evalRPN(test3) << endl;

}

/*
 Main idea:
 Стак використовується для збереження проміжних результатів.
 Проходимось по даному масиві, якщо поточний елемент є числом,
 то його одразу закидують в стак, якщо потрапляємо на якись
 знак операції, то зі стаку дістаємо останні два елементи та
 в додатковій функції виконуємо відповідну операцію, а її результат
 додаємо в стак.

 Така процедура повторюється, поки не пройдемо всі елементи масиву,
 після чого в стаці залишиться лише одне число, яке буде нашим результатом.

 Часова складність алгоритму: O(n)
*/