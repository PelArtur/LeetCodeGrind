/*
 https://leetcode.com/problems/string-compression/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

    class Solution
    {
    public:
        int compress(vector<char>& chars)
        {
            char currChar;
            int occurrence;
            int currCharInd = 0;
            int i = 0;

            while( i < chars.size() )
            {
                currChar = chars[i];
                occurrence = 0;
                chars[currCharInd++] = currChar;
                while(i < chars.size() && currChar == chars[i])
                {
                    occurrence++;
                    i++;
                }

                if(occurrence > 1)
                    for(char num : to_string(occurrence))
                        chars[currCharInd++] = num;
            }

            return currCharInd;
        }
    };


int main()
{
    Solution solution;
    vector<char> test1 = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'd', 'd', 'd', 'd'};
    vector<char> test2 = {'a'};
    vector<char> test3 = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c', 'c', 'c'};
    vector<char> test4 = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                          'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                          'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                          'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',
                          'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',};

    cout << solution.compress(test1) << endl;
    cout << solution.compress(test2) << endl;
    cout << solution.compress(test3) << endl;
    cout << solution.compress(test4) << endl;
}

/*
 Main Idea:
 Є два поінтери. Один іде по стрічці і рахує кількість літер,
 інший відповідає за запис значень у фінальний результат.

 Повертаємо значення поінтера, який відповідає за запис чисел,
 оскільки в кінці він буде знаходитись на один індекс вперед
 від результату.

 Складність роботи алгоритму: O(n)
*/