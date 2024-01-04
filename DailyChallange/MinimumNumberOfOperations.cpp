/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/?envType=daily-question&envId=2024-01-04
*/

#include <map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        map<int, int> numbers;
        int result = 0;
        int temp = 0;
        int ost = 0;

        for(int number : nums){
            numbers[number]++;
        }
        for(pair<int, int> number : numbers){
            temp = number.second/3;
            ost = number.second%3;
            if(number.second == 1){
                return -1;
            }
            if(ost == 0){
                result += temp;
            } else{
                result += temp + 1;
            }
        }
        return result;
    }
};
/*
 Main idea:

 Будь-яке число можна розкласти на суму 2 та 3
 Граєм від того, що найвигідніше юзати трійку як
 одну операцію. Проте, трійку можна розкласти на
 дві операції за потреби(3 + 1 = 4, 4/2 = 2)
 Тому ми по дефолту ділим на 3 як найбільш
 вигідний хід. Далі, якщо остачі немає, додаєм
 до результату, якщо остача є, то там або 2 або 1
 у випадку, якщо там 1 ми розкладаємо нашу одну 3
 на дві операції (3 + 1 = 4, 4/2 = 2) це виходить + 1
 операція(бо трійка як операція враховується)
 Якщо там 2 додаєм 1 операцію, оскільки двійку можна
 помістити за одну операцію.
 */