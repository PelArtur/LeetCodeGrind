/*
 https://leetcode.com/problems/largest-substring-between-two-equal-characters/?envType=daily-question&envId=2024-01-09
 */

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<int, int> characters;
        int result = -1;
        for(int idx = 0; idx < s.size(); ++idx){
            if(characters[s[idx]] == 0){
                characters[s[idx]] = idx + 1;
            } else{
                result = max(result, idx - characters[s[idx]]);
            }
        }
        return result;
    }
};

/*
 Main idea:

 Зберігаємо в мапу індекс першого входження
 символа, при зустрічанні нового перевіряємо
 чи він вже є в мапі. Якщо є, віднімаємо від
 індексу поточного символу індекс в мапі.
 */