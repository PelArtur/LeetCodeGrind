/*
https://leetcode.com/problems/find-the-highest-altitude/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestAltitude(vector<int>& gain)
    {
        auto df = vector<int>(gain.size()+1, 0);
        int max = 0;
        for(size_t i = 1; i <= gain.size(); ++i)
        {
            df[i] = df[i-1] + gain[i-1];
            if(df[i] > max)
                max = df[i];
        }

        return max;
    }
};

int main()
{
    Solution solution;
    vector<int> gain = {-5, 1, 5, 0, -7};

    cout << solution.largestAltitude(gain);
}

/*
  Створюємо масив розміром на 1 більший за масив gain.
  У цьому масиві зберігатиметься значення висоти на
  і-ітерації. Висота на і-ітерація це сума всіх різниць
  висот від 0 до і-1 індекса в gain. У процесі оброханку
  поточний висоти вона порівнюється з максимальним значенням.
*/