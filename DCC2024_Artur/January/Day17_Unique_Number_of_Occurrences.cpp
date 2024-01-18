/*
 https://leetcode.com/problems/unique-number-of-occurrences/?envType=daily-question&envId=2024-01-17
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int>& arr)
    {
        unordered_map<int, int> occurrences;
        unordered_map<int, bool> occurrencesAppear;

        for(auto num : arr)
            occurrences[num]++;

        for(auto value : occurrences)
        {
            if( occurrencesAppear[value.second] )
                return false;
            occurrencesAppear[value.second] = true;
        }

        return true;
    }
};


int main()
{
    Solution solution;
    vector<int> test1 = {1, 2, 2, 1, 1, 3};
    vector<int> test2 = {1, 2};
    vector<int> test3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};

    cout << solution.uniqueOccurrences(test1) << endl;
    cout << solution.uniqueOccurrences(test2) << endl;
    cout << solution.uniqueOccurrences(test3) << endl;
}

/*
 Main idea:
 Є дві мапи:
 - occurrences — зберігає кількість входжень кожного числа,
 - occurrencesAppear — зберігає True, якщо ключ або ж кількість
   входжень вже було в масиві, тобто, якщо число 1 повнорюється
   5 раз в масиві arr, тоді occurrencesAppear[5] = true

 Рахуємо кількість входжень всіх чисел масиву. Проходимось по
 мапі occurrences, якщо якась кількість входжень вже зустрічалась,
 то повертаємо false, якщо ні, то для даної кількості входжень записуємо
 значення true.

 Після виконання цього циклу, повертаємо true.
*/