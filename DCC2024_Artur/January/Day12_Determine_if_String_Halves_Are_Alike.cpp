/*
 https://leetcode.com/problems/determine-if-string-halves-are-alike/?envType=daily-question&envId=2024-01-12
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s)
    {
        int half = (int) s.size() / 2;
        int first = 0, second = 0;
        char vowels[] = {'A', 'E', 'I', 'O', 'U'};

        for(int i = 0; i < half; ++i)
            for(auto vowel : vowels)
                if( s[i] == vowel || s[i] == vowel + 32 )
                    first++;

        for(int j = half; j < s.size(); ++j)
            for(auto vowel : vowels)
                if( s[j] == vowel || s[j] == vowel + 32 )
                    second++;

        return first == second;
    }
};


int main()
{
    auto *solution = new Solution();

    string test1 = "book";
    string test2 = "textbook";
    string test3 = "Uo";

    cout << solution->halvesAreAlike(test1) << endl;
    cout << solution->halvesAreAlike(test2) << endl;
    cout << solution->halvesAreAlike(test3) << endl;

    delete solution;

    return 0;
}

/*
 Main idea:
 Проходимось спершу по першій половині стрінга, рахуємо кількість
 входжень голосних літер. Проходимось по масиву:
 ['A', 'E', 'I', 'O', 'U'], а також кожного числа + 32, оскільки
 по ASCII коду малі літери йдуть на 32 значення дальше.

 Як покращити код?
 Можна зробити масив лише з маленьких літер і перевіряти чи s[i].lower()
 є рівним літері із масиву, або зробити if-statement на 5 перевірок.

 Складність O(N)
*/
