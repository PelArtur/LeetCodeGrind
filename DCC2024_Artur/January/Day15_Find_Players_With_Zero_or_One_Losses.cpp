/*
 https://leetcode.com/problems/find-players-with-zero-or-one-losses/?envType=daily-question&envId=2024-01-15
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches)
    {
        unordered_map<int, int> loses;
        for(auto match : matches)
        {
            if( !loses[match[0]] )
                loses[match[0]] = 0;
            loses[match[1]]++;
        }
        vector<vector<int>> answer = {{}, {}};
        for(auto loser : loses)
        {
            if( !loser.second )
                answer[0].push_back(loser.first);
            else if( loser.second == 1 )
                answer[1].push_back(loser.first);
        }

        sort(answer[0].begin(), answer[0].end());
        sort(answer[1].begin(), answer[1].end());

        return answer;
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> test1 = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    vector<vector<int>> test2 = {{2,3},{1,3},{5,4},{6,4}};

    solution.findWinners(test1);
    solution.findWinners(test2);
}

/*
 Main idea:
 Створюємо мапу, яка міститиме за ключем номер гравця, а за
 значенням кількість його поразок. Також у процесі додаємо
 переможця в цю мапу, якщо його там ще не було і присвоюємо
 значення 0, щоб коли будемо перевіряти мапу і в якогось гравця
 було 0 поразок, то він містився б у цій мапі.

 Обходимо мапу, якщо в гравця 0 поразок, додаємо його в перший
 масив результату, а якщо 1 поразка, то відповідно в другий.

 Сортуємо обидва масиви й повертаємо результат.

 Складність роботи алгоритму: O(nlogn).
*/