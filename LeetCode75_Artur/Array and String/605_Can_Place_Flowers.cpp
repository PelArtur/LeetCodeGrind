/*
 https://leetcode.com/problems/can-place-flowers/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n)
    {
        if(flowerbed.size() == 1)
        {
            return !n || !flowerbed[0] && n <= 1;
        }

        int possibleN = 0;
        if(!flowerbed[0] && !flowerbed[1])
        {
            flowerbed[0] = 1;
            possibleN++;
        }
        if(!flowerbed[flowerbed.size()-1] && !flowerbed[flowerbed.size()-2])
        {
            flowerbed[flowerbed.size()-1] = 1;
            possibleN++;
        }

        for(size_t i = 1; i < flowerbed.size() - 1; ++i)
        {
            if(!flowerbed[i] && !flowerbed[i-1] && !flowerbed[i+1])
            {
                flowerbed[i] = 1;
                possibleN++;
            }
        }

        return possibleN >= n;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1, 0, 0, 0, 1};
    int n1 = 1;

    vector<int> test2 = {1, 0, 0, 0, 1};
    int n2 = 2;

    cout << solution.canPlaceFlowers(test1, n1) << endl;
    cout << solution.canPlaceFlowers(test2, n2) << endl;
}

/*
 Main Idea:
 Якщо масив є розміром 1, то повернути true, якщо n є рівним 0 або
 значення в масиві 0 та n є не більшим за 1, інакше false.

 В інших випадках перевіряємо перший та останній елемент чи вони є
 вільними та чи суміжні з ними елементи є також вільними. Якщо
 виконується ця умова, то в масиві замість 0 перезаписуємо 1 і до
 загального значення можливих посадок додаємо один.

 Дальше проходимось масивом від 1 за індексом елементом до передостаннього.
 Перевіряємо чи за індексами i, i-1 та i+1 є вільні місця, якщо так, то на
 позицію i записуємо 1 і до possibleN додаємо одиницю.

 Якщо possibleN є більшим або рівним до очікованого n, то повертаємо true, в
 інщому випадку відповідно false.

 Найкраща реалізація цього завдання з сайту:

 class Solution {
 public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        f.emplace(f.begin(), 0);
        f.emplace_back(0);
        size_t c{};
        for (size_t i{}; i<f.size()-2; ++i) {
            if (!f[i] && !f[i+1] && !f[i+2]) ++c, ++i;
        }
        return c>=n;
    }

 Спершу додаємо 0 на початок та кінець масиву, дальше проходимось циклом за тим
 ще принципом, що був описаний вище.
};

*/