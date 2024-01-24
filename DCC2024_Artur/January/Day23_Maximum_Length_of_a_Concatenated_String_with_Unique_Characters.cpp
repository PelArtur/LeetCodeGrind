/*
 https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/?envType=daily-question&envId=2024-01-23
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    vector<bool> isContains;
public:
    bool overlap(string &str)
    {
        for(auto chr : str)
            if( isContains[chr - 'a'] )
                return true;
        return false;
    }

    int backtracking(vector<string>& arr, int i)
    {
        if( i == arr.size() )
        {
            int res = 0;
            for(auto val : isContains)
                if( val )
                    res++;
            return res;
        }

        if( !overlap(arr[i]) )
        {
            int without = backtracking(arr, i + 1);
            for(auto chr : arr[i])
                isContains[chr - 'a'] = true;
            int with = backtracking(arr, i + 1);
            return max(without, with);
        }

        return backtracking(arr, i + 1);
    }


    int maxLength(vector<string>& arr)
    {
        isContains = vector<bool>(26, false);
        return backtracking(arr, 0);
    }
};


int main()
{
    Solution solution;

    vector<string> test1 = {"un", "iq", "ue"};
    vector<string> test2 = {"cha", "r", "act", "ers"};
    vector<string> test3 = {"abcdefghijklmnopqrstuvwxyz"};

    cout << solution.maxLength(test1) << endl;
    cout << solution.maxLength(test2) << endl;
    cout << solution.maxLength(test3) << endl;
}

/*
 Main idea:
*/