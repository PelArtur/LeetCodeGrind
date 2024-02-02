/*
 https://leetcode.com/problems/sequential-digits/?envType=daily-question&envId=2024-02-02
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string patern = "123456789";
        vector<int> result;
        for(int fast = 2; fast <= 9; fast++){
            for(int slow = 0; slow <= 9 - fast; slow++){
                int number = stoi(patern.substr(slow, fast));
                if(number >= low && number <= high){
                    result.push_back(number);
                }
            }
        }
        return result;
    }
};

/*
 Main idea:

 Вибираємо розмір, що будемо перевіряти. Йдемо від малих до великих розмірів
 Спочатку обраємо всі числа з довжиною в два. Беремо всі можливі числа такого
 розміру, що починаються на різних позиціях. Якщо число, що утворює ця
 послідовність більше ніж мінімум і менше ніж максимум, додаємо його до масиву.
 Таким чином спочатку ми послідовно додаємо числа одного розміру що завжди
 збільшуються, таким чином не потребуючи додаткового сортування.
 */