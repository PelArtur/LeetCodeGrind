/*
 https://leetcode.com/problems/is-subsequence/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if( s.size() > t.size() )
            return false;

        int sPoint = 0, tPoint = 0;

        while( sPoint < s.size() && tPoint < t.size() )
        {
            if( s[sPoint] == t[tPoint] )
                sPoint++;
            tPoint++;
        }

        return sPoint == s.size();
    }
};

int main()
{
    Solution solution;

    string s1 = "abc";
    string t1 = "ahbgdc";

    string s2 = "axc";
    string t2 = "ahbgdc";

    cout << solution.isSubsequence(s1, t1) << endl;
    cout << solution.isSubsequence(s2, t2) << endl;
}

/*
 Main Idea:
 Є два поінтера, один для стрічки s, інший для стрічки t.
 Цикл while виконується до тих пір поки один із поінтерів
 не зайде за межі своєї стрічки.

 Спершу перевіряється чи розмір стрічки s не є більшим за
 розмір t, в інщому випадку вона не зможе бути підпослідовністю.
 Дальше в циклі while порівнюються символи за обома поінтерами
 обох стрічок, якщо вони рівні, то поінтер стрічки s посувається,
 поінтер стрічки t посувається на кожній ітерації.

 Повертається булеве значення, чи поінтер стрічки s дійшов до кінця
 стрічки.
*/