/*
 https://leetcode.com/problems/determine-if-two-strings-are-close/description/?envType=daily-question&envId=2024-01-14
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if( word1.size() != word2.size() )
            return false;
        auto charsWord1 = vector<int>(26, 0);
        auto charsWord2 = vector<int>(26, 0);

        for(auto chr : word1)
            charsWord1[chr - 'a']++;
        for(auto chr : word2)
            charsWord2[chr - 'a']++;

        unordered_map<int, int> freqWord1;
        unordered_map<int, int> freqWord2;
        for(int i = 0; i < 26; ++i)
        {
            if( charsWord1[i] && !charsWord2[i] )
                return false;
            freqWord1[charsWord1[i]]++;
            freqWord2[charsWord2[i]]++;
        }

        for(auto freq : freqWord1)
            if( freqWord2[freq.first] != freq.second )
                return false;

        return true;
    }
};


int main()
{
    Solution solution;

    vector<string> test1 = {"abc", "bca"};
    vector<string> test2 = {"a", "aa"};
    vector<string> test3 = {"cabbba", "abbccc"};
    vector<string> test4 = {"aaabbbbccddeeeeefffff", "aaaaabbcccdddeeeeffff"};

    cout << solution.closeStrings(test1[0], test1[1]) << endl;
    cout << solution.closeStrings(test2[0], test2[1]) << endl;
    cout << solution.closeStrings(test3[0], test3[1]) << endl;
    cout << solution.closeStrings(test4[0], test4[1]) << endl;
}

/*
 Main idea:
 Перевірити чи обидва слвоа мають однаковий розмір, набір символів
 та однакові кількості входжень цих символів у словах.

 Ідея лишилась та сама, але її імплементація в рази краща в цьому
 дейліку, ніж до того в цьому файлі в паці LeetCode75.

 Є два масиви charsWord1 та charsWord1, які складаються з 26 об'єктів.
 і індекс відповідає за і + 1 букву в латинському алфавіті. У цих
 масивах зберігається кількість повторень кожної букви в обох словах.
 Індекс забезпечується різницею значення літери в ASCII і 'a'.

 Перевіряємо чи є присутні букви в обох масивах і раїуємо кількість
 значень якогось входжень у відповідні масиви freqWord1 та freqWord2.
 Тобто freqWord1[7] = 1, означає, що в першому слові є одна буква, яка
 зустрічається 7 разів.

 Перевіряємо чи значення в freqWord1 та freqWord2 збігаються.

 Якщо всі із вище згаданих перевірок пройшли успішно, то повертається
 True.

 Чому саме такі умови, описано в пайтон файлі.

 Часова складність алгоритму: O(n).
*/