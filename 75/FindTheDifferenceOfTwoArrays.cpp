/*
 https://leetcode.com/problems/find-the-difference-of-two-arrays/description/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setOne(nums1.begin(), nums1.end());
        unordered_set<int> setTwo(nums2.begin(), nums2.end());

        vector<int> distinctNumsOne, distinctNumsTwo;
        for(int number: setOne){
            if(setTwo.count(number) == 0){
                distinctNumsOne.push_back(number);
            }
        }
        for(int number: setTwo){
            if(setOne.count(number) == 0){
                distinctNumsTwo.push_back(number);
            }
        }
        return {distinctNumsOne, distinctNumsTwo};
    }
};

/*
 Main idea:

 Кожен масив запхати в сет
 Для чисел з першого сета перевірити, чи існує таке число в другому сеті
 Якщо ні, додаємо число до нашого результату
 Таке ж для другого сету.
 */

