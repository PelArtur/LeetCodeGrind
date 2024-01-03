/*
 https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03
*/

#include <iostream>
#include "vector"
#include "string"
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string>& bank)
    {
        int prevLasers = 0;
        int beam = 0;

        for(const auto& row : bank)
        {
            int currLasers = 0;
            for(auto cell : row)
                if(cell == '1')
                    currLasers++;
            if(currLasers)
            {
                beam += prevLasers * currLasers;
                prevLasers = currLasers;
            }
        }

        return beam;
    }
};

int main()
{
    vector<string> test = {"011001","000000","010100","001000"};
    Solution solution;

    cout << solution.numberOfBeams(test);
}

/*
 Main idea:
 Є три змінні prevLasers — кількість лазерів в останньому ряді, де
 були лазери, currLasers — кількість лазерів у поточному ряді та
 beam — загальна кількість променів у банку.

 Проходитись по кожному рядку, рахуючи кількість одиниць(лазерів).
 Якщо їхня кількість відмінна від 0, то до beam додаємо добуток
 кількості лазерів на поточному та в останньому ряді у якому були
 лазери. Перезаписуємо значення prevLasers на currLasers.

 Чому prevLasers не обов'язково попередній ряд?
 Усе тому, що за умовою лазери можуть утворювати промінь через
 декілька рядів, за умовою, що на них не було жодного іншого лазера

 Приклад:

 011100
 000000
 000000
 010010
 000100

 Тут лазери з першого ряду будуть утворювати промені із лазерами з 4
 ряду, бо в 2 та 3 рядах немає жодного лазера. Проте 1 ряд не може
 утворювати промені з 5 рядом, оскільки між ними в 4 ряді розташовані
 2 лазера.
 */