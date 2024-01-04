/*
 https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

bool find(vector<int> &arr, int arg);

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        if( word1.size() != word2.size())
            return false;

        unordered_map<char, int> charOccurrence1; //word1
        unordered_map<char, int> charOccurrence2; //word2
        vector<int> occurrences2;
        set<char> charsWord1;

        for(size_t i = 0; i < word1.size(); ++i)
        {
            charOccurrence1[word1[i]]++;
            charOccurrence2[word2[i]]++;
            charsWord1.emplace(word1[i]);
        }

        for( auto chr : charOccurrence2 )
        {
            if( charsWord1.find(chr.first) == charsWord1.end() )
                return false;
            occurrences2.push_back(chr.second);
        }

        for( auto chr : charOccurrence1 )
            if( !find(occurrences2, chr.second) )
                return false;

        return true;
    }
};


bool find(vector<int> &arr, int arg)
{
    for(int &arrArg : arr)
    {
        if( arrArg == arg )
        {
            arrArg = 0;
            return true;
        }
    }

    return false;
}


int main()
{
    Solution solution;

    vector<string> test1 = {"abc", "bca"};
    vector<string> test2 = {"a", "aa"};
    vector<string> test3 = {"cabbba", "abbccc"};

    cout << solution.closeStrings(test1[0], test1[1]) << endl;
    cout << solution.closeStrings(test2[0], test2[1]) << endl;
    cout << solution.closeStrings(test3[0], test3[1]) << endl;
}

/*
 Main idea:
 Перевірити чи обидва слвоа мають однаковий розмір, набір символів
 та однакові кількості входжень цих символів у словах.

 Створюємо дві мапи для кожного із слів, які зберігатимуть кількість
 входжень кожного символа в цих словах. Паралельно з додаванням символів
 у ці мапи, додаються символи з першого рядка в сет.
 У наступному циклі проходимось по елементах, які є в мапі другого слова і
 перевіряємо чи вони є присутніми в сеті з символів першого слова, якщо ця
 умова не виконується, то повертаємо false.

 В останньому циклі перевіряємо чи значення кількості входжень у першого слова є
 такими ж, як у другого слова, якщо ця умова не виконується повертаємо false.

 Якщо всі перевірки пройшли коректно, то повертається true.
*/