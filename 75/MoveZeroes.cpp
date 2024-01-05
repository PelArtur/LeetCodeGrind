/*
 https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCounter = 0;
        for(int idx = 0; idx < nums.size(); ++idx){
            if(nums[idx] != 0 && zeroCounter != 0){
                nums[idx - zeroCounter] = nums[idx];
                nums[idx] = 0;
            } else if(nums[idx] == 0){
                zeroCounter += 1;
            }
        }
    }
};

int main(){
    vector<int> input = {0,1,0,3,12};

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

 UPD:
 Рухаємось по масиву, якщо зустрічаємо нуль, збільшуємо кількість
 нулів на один. Якщо зустрічаємо не нуль і кількість нулів не
 дорівнює 0, то міняємо початок нулів(шукаємо його за індекс-кількість
 нулів, адже за пойнтером завжди йдуть нулі). Якщо не нуль, але кількість
 нулів 0, то нічого не робим.
 */

