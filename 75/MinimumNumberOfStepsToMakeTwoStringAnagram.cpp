/*
 https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/?envType=daily-question&envId=2024-01-13
 */

class Solution {
public:
    int minSteps(string s, string t) {
        int counter = 0;
        map<char, int> letterCounter;


        for(int idx = 0; idx < s.size(); ++idx){
            letterCounter[s[idx]]++;
        }
        for(int idx = 0; idx < t.size(); ++idx){
            letterCounter[t[idx]]--;
        }
        for(auto letterInfo : letterCounter){
            if(letterInfo.second > 0){
                counter += letterInfo.second;
            }
        }

        return counter;
    }
};


/*
 Main idea:


 Анаграма - у слові однакові слова, але вони в різній послідовності.
 Для того щоб порахувати, скільки букв потрібно змінити, щоб утворилась
 анаграма, потрібно порахувати скільки букв є різними між двома словами,
 і повернути цю кількість.

 Для цього записуємо для кожної букви її кількість в мапу.
 Запускаєм цикл, додаємо до ключа в мапі +1 щоб збільшити
 кількість входжень певної букви.
 Робим таке ж для іншої стрінги, тільки тепер віднімаємо входження, щоб
 занотувати присутність цієї букви в іншому слові.

 Додаємо всі значення букв, які більше нуля, таким чином якщо нам не вистачає
 якихось букв для створення анаграми, значення для ключа буде > 0.

 Суму повертаємо.



 Моє трішки гарніше рішення:

class Solution {
public:
    int minSteps(string s, string t) {
        int counter = 0;
        vector<int> letterCounter(26, 0);


        for(auto letter : s){
            letterCounter[letter - 'a']++;
        }

        for(auto letter : t){
            if(letterCounter[letter - 'a'] <= 0){
                counter++;
            }
            letterCounter[letter - 'a']--;
        }


        return counter;
    }
};
 Тут юзаю мапу як вектор('a' - 'a' = 0, Для b-а буде 1, тому
 валідно його юзати), працює швидше ніж звичайна мапа.

 Також тут краще реалізований каунтер, не винесений в окрему форку,
 а реалізований за допомогою різниці символів.
 Якщо в t забагато якихось символів, то результат буде від'ємним в масиві,
 тому якщо приходить запит змінити щось, а значення в масиві за індексом
 <= 0, це означає що ми рахуємо зараз лишній символ який треба буде змінити.
 Тому валідно працює
 */

