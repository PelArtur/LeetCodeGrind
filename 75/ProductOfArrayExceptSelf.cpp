/*
 https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75
 */
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size());

        result[0] = 1;

        for(int idx = 1; idx < nums.size(); ++idx){
            result[idx] = result[idx - 1] * nums[idx - 1];
        }

        int multiplier = 1;
        for(int idx = nums.size() - 1; idx >= 0; --idx){
            result[idx] *= multiplier;
            multiplier *= nums[idx];
        }

        return result;
    }
};

/*
 Main idea:

 Створюємо масив який буде містити результат.
 Спочатку пройдемось зліва направа таким чином
 Значення наступного елемента це попередній
 результат множення * попередній елемент.
 Таким чином поточний елемент буде містити всі
 перемножені значення, що були перед ним окрім
 себе.

 Далі проходимось справа наліво. Оскільки нам
 ще треба домножити до прикладу перший елемент
 на всі праві елементи. Для цього йдемо справа,
 множимо поточне число на змінну Multiplier{
 спочатку сетаєм її як 1, бо кінцеве значення
 містить добуток всіх інших значень}
 змінну Multiplier множимо на поточне число і
 йдемо в наступну ітерацію. Таким чином кожне
 ліве число буде множитись на добуток правих
 чисел, що не були включені в його значення.


 */