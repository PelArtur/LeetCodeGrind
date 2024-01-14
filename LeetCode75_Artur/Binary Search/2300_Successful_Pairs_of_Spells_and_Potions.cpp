/*
 https://leetcode.com/problems/successful-pairs-of-spells-and-potions/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &arr, long long elem, long long spellBuff)
    {
        int l = 0, r = (int) arr.size() - 1;
        int mid;
        while(l <= r)
        {
            mid = l + (r - l) / 2;
            if( arr[mid] * spellBuff < elem )
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l < arr.size() ? l : (int) arr.size();
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        sort(potions.begin(), potions.end());

        vector<int> res = vector<int>(spells.size(), 0);
        for(int i = 0; i < spells.size(); ++i) \
            res[i] = (int) potions.size() - upperBound(potions, success, spells[i]);

        return res;
    }
};


int main()
{
    Solution solution;

    vector<int> test1Spells = {5, 1, 3};
    vector<int> test1Potions = {1, 2, 3, 4, 5};
    vector<int> test2Spells = {3, 1, 2};
    vector<int> test2Potions = {8, 5, 8};
    vector<int> test3Spells = {1, 2, 3, 4, 5, 6, 7};
    vector<int> test3Potions = {1, 2, 3, 4, 5, 6, 7};

    solution.successfulPairs(test1Spells, test1Potions, 7);
    solution.successfulPairs(test2Spells, test2Potions, 16);
    solution.successfulPairs(test3Spells, test3Potions, 25);
}

/*
 Main idea:
 Відсортовуємо масиву potions.
 За допомогою функції upperBound шукаємо індекс першого елемента
 добуток якого з поточним spell є більшим за success. Якщо такого
 елементу немає, то функція верне розмір заданого масиву.

 До результату поточного spell записуємо різницю між розміром масиву
 potions та результатом вище описаної функції. Ця різниця нам дає
 кількість елементів, добуток яких з spell є більшим за success.

 Часова складність алгоритму: O(nlogn)
 Сортування за nlogn та n викликів функції upperBound, яка працює за
 logn.
*/