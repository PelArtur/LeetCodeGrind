/*
 https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0){
            return true;
        }

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;

    }
};
/*
 Main idea:

 Якщо це 0-ий елемент у списку і перший елемент 0, ставим 1.
 Якщо це останній елемент у списку == 0 і поп. теж - теж 1.
 В інших випадках якщо цей ел. 0, попередній і наступний 0,
 ставим 1.
 */