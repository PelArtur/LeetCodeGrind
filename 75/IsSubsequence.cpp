/*
 https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
 */

class Solution {
public:
    bool isSubsequence(string substring, string string) {
        int pointer = 0;
        for(int idx = 0; idx < string.size(); ++idx){
            if(string[idx] == substring[pointer]){
                pointer++;
            }
        }
        return pointer == substring.size();
    }
};

/*
 Main Idea:

 Кожного разу як у стрінгу зустрічаю current
 символ сабстрінга, збільшую пойнтер
 Якщо пойнтер дорівнюватиме розміру сабстрінга
 то це буде тру, адже на останньому символі
 сабстрінга пойнтер дорівнює n-1, то +1 зробить
 n. Тому повертаю пойнтер дорівнює розміру
 */