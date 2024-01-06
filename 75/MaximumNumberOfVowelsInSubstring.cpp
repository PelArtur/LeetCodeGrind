/*
 https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75
 */
#include <string>

using namespace std;

class Solution {
public:
    int maxVowels(string str, int k) {
        int result = 0;
        int maxVowels = 0;
        for(int idx = 0; idx < str.size(); ++idx){
            if(idx >= k && (str[idx - k] == 'a' || str[idx - k] == 'e' || str[idx - k] == 'i' || str[idx - k] == 'o' || str[idx - k] == 'u')){
                --maxVowels;
            }
            if(str[idx] == 'a' || str[idx] == 'e' || str[idx] == 'i' || str[idx] == 'o' || str[idx] == 'u'){
                ++maxVowels;
            }
            result = max(maxVowels, result);
        }
        return result;
    }
};


/*
 Main idea:

 Рухаємось по масиву віконцем довжиною к
 маємо змінну, що рахує кількість голосних
 у цьому віконці. Якщо новий символ голосний,
 додаємо 1 до змінної, якщо символ, що вилетів
 голосний віднімаємо 1. Кожного разу перевіряємо
 нашу відповідь чи вона більша ніж поточне значення.
 */