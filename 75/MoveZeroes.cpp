/*
 https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroPointer = -1;
        int zeroNumbers = 0;

        for(int idx = 0; idx < nums.size(); ++idx){
            if(nums[idx] != 0 && zeroPointer != -1){
                nums[zeroPointer] = nums[idx];
                nums[zeroPointer + zeroNumbers] = 0;
                zeroPointer++;
            } else {
                if(zeroPointer == -1){
                    zeroPointer = idx;
                }
                zeroNumbers++;
            }
        }
    }
};

int main(){
    vector<int> input = {0};

    Solution().moveZeroes(input);

    for(int idx = 0; idx < input.size(); idx++){
        cout << input[idx] << " ";
    };

    return 1;
}

/*
 Main idea:

 Рухаємось по масиву, поки не зустрінемо перше входження
 0. Записуємо це входження, збільшуємо кількість нулів
 на 1. Йдемо далі, кожного разу як бачимо 0 збільшуємо
 кількість 0 на 1, кожного разу як бачимо не 0, міняємо
 це число з першим нулем(у нас є мала послідовність нулів,
 а в нас є вказівник на початок цих нулів), а замість нього
 ставим нуль.
 */

