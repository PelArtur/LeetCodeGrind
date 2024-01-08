/*
 https://leetcode.com/problems/unique-number-of-occurrences/submissions/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> firstMap;
        map<int, int> secondMap;
        for(int number : arr){
            firstMap[number] += 1;
        }

        for(auto pair : firstMap){
            if(secondMap[pair.second] == 1){
                return false;
            }
            secondMap[pair.second] = 1;
        }
        return true;
    }
};

/*
 Main idea:

 Рахуємо кількість входжень кожного числа за
 допомогою мапи. За допомогою іншої мапи
 дивимось, чи вже було число з такою кількі-
 стю траплянь. Якщо було, повертаємо false.
 У кінці повертаєм тру.
 */