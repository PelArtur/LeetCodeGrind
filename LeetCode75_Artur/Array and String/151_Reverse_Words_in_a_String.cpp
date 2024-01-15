/*
 https://leetcode.com/problems/reverse-words-in-a-string/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        deleteExtraSpaces(s);

        int inputSize = (int) s.size();
        int mid = inputSize / 2;
        for(int i = 0; i < mid; ++i)
            swap(s[i], s[inputSize - 1 - i]);

        int curr = 0;
        int wordStart = 0;
        int wordEnd;
        while (curr < inputSize)
        {
            if (s[curr] == ' ')
            {
                wordEnd = curr - 1;
                while( wordStart < wordEnd )
                    swap(s[wordStart++], s[wordEnd--]);

                wordStart = curr + 1;
            }

            curr++;
        }

        wordEnd = curr - 1;
        while( wordStart < wordEnd )
            swap(s[wordStart++], s[wordEnd--]);

        return s;
    }

    void deleteExtraSpaces(string &s)
    {
        int notSpace = 0;
        int curr = 0;

        //delete spaces in the start
        if( s[0] == ' ')
        {
            while( s[notSpace] == ' ' )
                notSpace++;

            while( s[notSpace] != ' ' )
            {
                s[curr++] = s[notSpace];
                s[notSpace++] = ' ';
            }
        }

        //delete spaces in the middle of word
        bool isSpace = false;
        while( curr < s.size() && notSpace < s.size() )
        {
            if( isSpace )
            {
                while( notSpace < s.size() && s[notSpace] == ' ' )
                    notSpace++;

                if( notSpace >= s.size() )
                    break;

                while( curr != notSpace && s[notSpace] != ' ' )
                {
                    if( notSpace >= s.size() )
                        break;
                    s[curr++] = s[notSpace];
                    s[notSpace++] = ' ';
                }
            }
            if( s[curr] == ' ' )
                isSpace = true;
            else
                isSpace = false;

            curr++;
            notSpace++;
        }

        //count and delete spaces in the end
        int endSpacesNum = 0;
        curr = (int) s.size() - 1;
        while (curr >= 0 && s[curr--] == ' ')
            endSpacesNum++;

        s.erase(s.size() - endSpacesNum, endSpacesNum);
    }
};



int main()
{
    Solution solution;
    string test1 = "the sky is blue";
    string test2 = "  hello world  ";
    string test3 = "a good   example";
    string test4 = "a             very                good               example      ngl    ";

    cout << solution.reverseWords(test1) << endl;
    cout << solution.reverseWords(test2) << endl;
    cout << solution.reverseWords(test3) << endl;
    cout << solution.reverseWords(test4) << endl;
}

/*
 Main idea:
 Видаляємо всі зайві пробіли.
 Дальше реверсимо все слово. Тоді отримуємо необхідний порядок
 лів за умовою, але вони теж реверснуті. Реверсимо кожне слово
 окремо.

 Часова складність алгоритму: O(n).
 Видалити пробіли: O(n)
 Реверснути всю стрічку: O(n)
 Реверснути всі слова в стрічці: O(n)
*/