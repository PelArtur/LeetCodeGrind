/*
 https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/?envType=study-plan-v2&envId=leetcode-75
 */
class Solution {
private:
    vector<string> allPossibleMessages;

    const vector<string> pad = { "", "", "abc", "def", "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
public:
    void findCombinations(string digits, int idx, string message){
        if(idx == digits.size()){
            allPossibleMessages.push_back(message);
            return;
        }

        for(char letter : pad[digits[idx] - '0']){
            message.push_back(letter);
            findCombinations(digits, idx + 1, message);
            message.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(size(digits) == 0){
            return {};
        }
        findCombinations(digits, 0, "");
        return allPossibleMessages;
    }
};
/*
 Main idea:

 Запускаємо рекурсію для першої цифри
 У рекурсії запускаємо цикл по всіх
 можливих символах цифри за індексом {idx}
 і додаєм по черзі в кінець повідомлення
 утворене повідомлення й індекс наступного
 числа передаємо на далі в рекурсію.
 {Після додавання і виклику рекурсії чистимо
 message від доданого символа, щоб некст виклик
 був без поточного символа(був унікальним)}
 Індекс вказує яка цифра буде розкудовуватись
 на цьому виклику функції.

 Base case:
 Індекс дорівнює розміру стрінги digits, додаємо
 message до всіх можливих повідомлень.
 */