/*
 https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/?envType=daily-question&envId=2024-01-13
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t)
    {
        unordered_map<char, int> lettersS;
        unordered_map<char, int> lettersT;

        for(auto letter : s)
            lettersS[letter]++;

        for(auto letter : t)
            lettersT[letter]++;

        int steps = 0;
        for(auto letter : lettersS)
            steps += letter.second - lettersT[letter.first] > 0 ? letter.second - lettersT[letter.first] : 0;

        return steps;
    }
};


int main()
{
    Solution solution;

    vector<string> test1 = {"bab", "aba"};
    vector<string> test2 = {"leetcode", "practice"};
    vector<string> test3 = {"anagram", "mangaar"};

    cout << solution.minSteps(test1[0], test1[1]) << endl;
    cout << solution.minSteps(test2[0], test2[1]) << endl;
    cout << solution.minSteps(test3[0], test3[1]) << endl;

    return 0;
}

/*
 Main idea:
 Створити дві мапи, які містять кількість входжень літери в
 словах s та t. Порівняти різницю між ними.

 Складність O(n)

 Покращення коду:
 Скоріше буде доступатись до літер через масив, а не мапу.
*/
