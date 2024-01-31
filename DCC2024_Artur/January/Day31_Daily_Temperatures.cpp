/*
 https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        stack<pair<int, int>> monoStack;
        vector<int> res = vector<int>(temperatures.size(), 0);

        for(int i = (int) temperatures.size() - 1; i >= 0; --i)
        {
            while( !monoStack.empty() && temperatures[i] >= monoStack.top().first )
                monoStack.pop();

            if( !monoStack.empty() )
                res[i] = monoStack.top().second - i;
            monoStack.push({temperatures[i], i});
        }

        return res;
    }
};


int main()
{
    vector<int> test1 = {73,74,75,71,69,72,76,73};
    vector<int> test2 = {30,40,50,60};
    vector<int> test3 = {30,60,90};

    Solution().dailyTemperatures(test1);
    Solution().dailyTemperatures(test2);
    Solution().dailyTemperatures(test3);

}

/*
 Main idea:
 Монотонний стак. Він міститиме пари елементів: (value, index), у
 зростаючому порядку. Першою вищою температурою в масиві буде першим
 елементом у стаку, який буде більший за поточну температуру.

 Допустимо ми зараз на і індексі, тоді попаємо стак до тих пір, поки на
 вершині не буде більше значення, записуємо різницю індексів у масив, і
 заносимо поточний елемент у стак.

 Якщо після того, як виконали попи стаку і стак залишився пустим. то це
 означає, що дальше немає дня, в якого температура була б вищою.

 Часова складність алгоритму: O(n)
*/