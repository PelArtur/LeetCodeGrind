/*
 https://leetcode.com/problems/two-sum/
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seenValues;
        for(int idx = 0; idx < nums.size(); ++idx){
            if(seenValues.find(target - nums[idx]) != seenValues.end())
                return {seenValues[target - nums[idx]], idx};
            seenValues[nums[idx]] = idx;
        }
        return {-1, -1};
    }
};

/*
 Main idea:

 Зберігаємо в мапу поточне значення й індекс за яким воно розташоване
 Для кожного значення перевіряємо, чи є в мапі таке значення, що в сумі
 з нашим дасть нам таргет.

 Іншими словами, ми віднімаємо від таргета поточне значення, і дивимось
 чи вже є таке значення в нашій мапі. Якщо таке значення є, то це означає
 що ми можемо отримати суму рівну таргету й повертаємо індекс значення
 з мапи й поточний індекс.

 */