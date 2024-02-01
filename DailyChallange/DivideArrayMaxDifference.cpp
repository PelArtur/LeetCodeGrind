/*
 https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01
 */

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> maxDiffArray(nums.size() / 3);
        for(int idx = 2; idx < nums.size(); idx+=3){
            if( max({nums[idx], nums[idx - 1], nums[idx - 2]}) -
                min({nums[idx], nums[idx - 1], nums[idx - 2]}) > k)
                return {};
            maxDiffArray[int(idx/3)] = {nums[idx - 2], nums[idx - 1], nums[idx]};
        }
        return maxDiffArray;
    }
};

/*
 Main idea:

 У цьому масиві буде такий розв'язок лише в тому випадку, якщо для
 кожного числа знайдеться своя трійка.
 У трійці різниця максимального й мінімального чисел має бути менша
 за k. У такому разі різниця з середнім елементом теж задовільняє
 умову.
 k = 5
 {1, 3, 6}
 max = 6, min = 1
 max - min = 5
 6 - 3 = 3
 3 - 1 = 2
 max Та min будують ліву та праву границю, а середній елемент це
 точка між ними.
 Якщо ця умова не виконується, то в масиві немає іншого числа, що
 може утворити трійку, адже наступне число після максимального ще
 більше за максимальне, що тільки буде збільшувати різницю з
 мінімальним елементом.

 Ми йдемо з кроком 3. Перевіряємо три попередні елементи.
 Якщо max - min > k, повертаємо пустий масив, в іншому випадку
 додаємо масив до результату.

 */