/*
 https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        auto dp = vector<vector<int>>(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for(int i = 1; i <= text1.size(); ++i)
        {
            for(int j = 1; j <= text2.size(); ++j)
                dp[i][j] = text1[i-1] == text2[j-1] ? dp[i-1][j-1] + 1 : max(dp[i][j-1], dp[i-1][j]);
        }

        return dp.back().back();
    }
};


int main()
{
    Solution solution;

    vector<string> test1 = {"abcde", "ace"};
    vector<string> test2 = {"abc", "abc"};
    vector<string> test3 = {"abc", "def"};

    cout << solution.longestCommonSubsequence(test1[0], test1[1]) << endl;
    cout << solution.longestCommonSubsequence(test2[0], test2[1]) << endl;
    cout << solution.longestCommonSubsequence(test3[0], test3[1]) << endl;
}

/*
 Main idea:
 Масив dp міститиме максимальну підпослідовність в dp[i][j]
 для стрічки 1 до і елемента та стрічки 2 до j елемента.
 Проходимось по всіх символах стрічки 1 та 2, тоді:
 - символи в обох стрічках співпали, отже маємо нову підпослідовність,
   яка відповідає умові завдання. Тоді для dp[i][j] заприсуємо розмір
   поточної підпослідовності, яка закінчується відповілним символом обох
   стрічок. Тому дивимось на попередедні два символи і до їх значення додаємо
   1, оскільки підпослідовність збільшилась.
 - символи в обох стрічках різні, тому дивимись яка підпослідовність є більшою,
   для попереднього символу стрічки 1 чи для попереднього символу стрічки 2.

 Таким чином ми забезпечуємо таку особливість, що dp[i][j] міститиме кількість
 символів у найдовшій підпослідовності для цих символів у відпоаідних стрічках,
 не залежно чи вони співпадають, чи ні.

 Часова складність алгоритму: O(mn), де m — розмір стрічки 1, n — розмір стрічки 2.
*/