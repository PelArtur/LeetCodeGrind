/*
 https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> seenNumbers(nums.size() + 1, 0);
        int duplicate = 0;
        int exception = 0;
        for(int idx = 0; idx < nums.size(); ++idx){
            seenNumbers[nums[idx]] += 1;
        }

        for(int idx = 1; idx < nums.size() + 1; idx++){
            if (seenNumbers[idx] == 0){
                exception = idx;
                if(duplicate != 0){
                    return {duplicate, exception};
                }
            } else if(seenNumbers[idx] == 2){
                duplicate = idx;
                if (exception != 0){
                    return {duplicate, exception};
                }
            }
        }
        return {duplicate, exception};
    }
};
/*
 Проходимось по масиву й рахуємо кожне входження
 Пізніше проходимось по кількості входжень.
 Якщо входжень нуль, то цифра була пропущена.
 Якщо входження два, то ця цифра є дублікатом.
 У кінці повертаємо дублікат та пропущену цифру
 */