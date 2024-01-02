/*
https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/?envType=daily-question&envId=2024-01-02
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> static findMatrix(vector<int>& nums) {
        int maxValue = 0;
        vector<int> uniqueNumbers;
        map<int, int> numbersQuantity;

        for(int number : nums){
            if (numbersQuantity[number] == 0){
                uniqueNumbers.push_back(number);
            }
            ++numbersQuantity[number];
            maxValue = max(numbersQuantity[number], maxValue);
        }
        vector<vector<int>> result(maxValue);

        for(int idx = 0; idx < maxValue; idx++){
            for(int number : uniqueNumbers){
                if(numbersQuantity[number] != 0){
                    --numbersQuantity[number];
                    result[idx].push_back(number);
                }
            }
        }

        return result;
    }
};

/*
Main idea:

Ми створюємо додатковий масив, що буде
містити кількість входженнь кожного числа.
Кожного разу, як ми зустрічаємо число ми перевіряємо
кількість входжень на попередньому кроці. Якщо ця кількість
вже є максимальною(тобто входжень є стільки скільки і рядків),
то ми створюємо новий рядок для нового входження і додаємо його туди,
збільшуючи кількість входжень на один. Якщо кількість входжень на
попередньому кроці є менша, ніж кількість рядків, то ми просто
додаємо число до існуючого рядка і збільшуєм кількість входжень на 1.

class Solution {
public:
    vector<vector<int>> static findMatrix(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> frequency(nums.size() + 1);

    for(int number : nums){
        if(frequency[number] == result.size()){
            result.push_back({});
        }

        result[frequency[number]].push_back(number);
        frequency[number]++;
    }

    return result;
    }
};

 */