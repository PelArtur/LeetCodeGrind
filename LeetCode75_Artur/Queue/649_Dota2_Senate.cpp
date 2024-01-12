/*
 https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate)
    {
        unordered_map<char, int> banned;
        unordered_map<char, int> numOfSenate;
        numOfSenate['R'] = 0;
        numOfSenate['D'] = 0;
        banned['R'] = 0;
        banned['D'] = 0;

        queue<char> availableSenate;
        for(auto sen : senate)
        {
            numOfSenate[sen]++;
            availableSenate.push(sen);
        }

        char currSenate;
        while( numOfSenate['R'] && numOfSenate['D'] )
        {
            currSenate = availableSenate.front();

            if( banned[currSenate] )
            {
                banned[currSenate]--;
                numOfSenate[currSenate]--;
            }
            else
            {
                ban(banned, currSenate);
                availableSenate.push(currSenate);
            }

            availableSenate.pop();
        }

        return numOfSenate['R'] ? "Radiant" : "Dire";
    }

    void ban(unordered_map<char, int> &banned, char senateWhoBan)
    {
        if( senateWhoBan == 'R' )
            banned['D']++;
        else
            banned['R']++;
    }
};


int main()
{
    Solution solution;
    string test1 = "RD";
    string test2 = "RDD";

    cout << solution.predictPartyVictory(test1) << endl;
    cout << solution.predictPartyVictory(test2) << endl;
}

/*
 Main idea:
 Є черга, яка містить всіх доступних для голосування сенатів.
 Дві мапи, banned відповідає за кількість забанених сенатів[X],
 а numOfSenate за кількість доступних сенатів[X].
 Спершу додаємо всіх сенатів у чергу та рахуємо їх кількість.

 Дальше виконуємо таку процедуру: якщо кількість забанених сенатів
 є більшою за нуль, то це значення та кількість доступних даних
 сенатів зменшуємо на 1. В іншому випадку цього сената додаємо в
 чергу, а значення забанених сенатів-противників збільшуємо на 1.

 Складність алгоритм: O(nlogn)
 Додавання в чергу зі стрічки: O(n)
 Обхід стрічки O(nlogn)


 Найкраще ріщення з Solutions:

 class Solution {
 public:
    string predictPartyVictory(string senate)
    {
        int score = 0;
        for (int i = 0; i < senate.size(); ++i)
        {
            const char ch = senate[i];
            if (ch == 'R')
            {
                if (score < 0)
                    senate.push_back('D');
                ++score;
            }
            else
            {
                if (score > 0)
                    senate.push_back('R');
                --score;
            }
        }
        return score > 0 ? "Radiant" : "Dire";
   }
 };
 Тут дана стрічка використовується, як черга.

*/
