/*
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int candiesSize = candies.size();
        vector<bool> result(candiesSize);
        int maxCandy = 0;
        for(int idx = 0; idx < candiesSize; ++idx){
            maxCandy = max(maxCandy, candies[idx]);
        }
        maxCandy -= extraCandies;
        for(int idx = 0; idx < candiesSize; ++idx){
            result[idx] = candies[idx] >= maxCandy;
        }
        return result;
    }
};

/*
Main idea:
За o(n) шукаєм максимум, від нього віднімаєм
кількість екстра цукерок, і порівнюєм чи
кожна дитина має більше цукерок ніж наш змінений
максимум. Оптимізація відбувається за рахунок того,
що віднімання не в циклі. Це пришвидшує дію алгосу.
 */