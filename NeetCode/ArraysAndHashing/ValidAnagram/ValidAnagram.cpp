/*
 https://leetcode.com/problems/valid-anagram/description/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> charOccurence(26);

        for(int idx = 0; idx < s.size(); ++idx){
            ++charOccurence[s[idx] - 'a'];
            --charOccurence[t[idx] - 'a'];
        }

        for(int idx = 0; idx < 26; ++idx){
            if(charOccurence[idx] != 0){
                return false;
            }
        }
        return true;

    }
};

/*
 Main idea:

 Проходимось по двом словам одночасно, для першого слова
 по індексу букви додаємо одиницю, для другого слова для
 індексу букви віднімаємо одиницю. Це все відбувається в
 одному масиві. Якщо кількість доданих і від'ємних чисел
 однакова, то всі елементи в масиві будуть нулями. Тоді
 повертаємо true, в іншому випадку false.
 */