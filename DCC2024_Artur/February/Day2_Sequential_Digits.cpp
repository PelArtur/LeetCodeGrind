/*
 https://leetcode.com/problems/sequential-digits/?envType=daily-question&envId=2024-02-02
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> allPositiveNums =
            {12, 23, 34, 45, 56, 67, 78, 89,
             123, 234, 345, 456, 567, 678, 789,
             1234, 2345, 3456, 4567, 5678, 6789,
             12345, 23456, 34567, 45678, 56789,
             123456, 234567, 345678, 456789,
             1234567, 2345678, 3456789,
             12345678, 23456789, 123456789};
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int> res;
        for(auto num : allPositiveNums)
        {
            if( num > high )
                break;
            else if( num >= low )
                res.push_back(num);
        }

        return res;
    }
};


int main()
{
    Solution().sequentialDigits(100, 300);
    Solution().sequentialDigits(1000, 13000);
}

/*
 Main idea:
 Створити масив зі всіма можливими значеннями і
 додавати елементи з нього в результат до тих пір,
 поки виконується умова low <= num <= high.

 Цей варіант є найбільш оптимізованим і є найбільш
 простим. Загальна кількість комбінацій становить
 36, що легко дозволяє розписати всі ці варіанти.

 Часова складність алгоритму: O(1)

 Другий реалізований варіант через sliding window
 Можна представити всі можливі такі числа, як
 підстрічки стрічки "123456789".
 Тому проходимось по цій стрічці "вікном", розміром
 від 1 до 9 і перевіряємо чи число входить в даний
 діапазон, якщо входить, то додаємо його в масив.

 Часова складність алгоритму: O(1)

 Загалом є багато підходів розв'язати цю задачу, ось
 декілька із часовою складність:

 - Брют форс: O(n)
 - Sliding window: O(1)
 - Queue: O(1)
 - BFS: O(1)
 - Trie: O(1)
 - Generated array: O(1)
*/