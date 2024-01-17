/*
 https://leetcode.com/problems/contains-duplicate/description/
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> numberFreq;
        for(int number : nums){
            if(numberFreq[number] == 1)
                return true;

            numberFreq[number] = 1;
        }

        return false;
    }
};

/*
 Main idea:

 Проходимось по списку, кожен елемент додаємо в мапу
 Якщо в мапі вже є такий елемент повертаєм true
 Повертаємо false в іншому випадку.
 */