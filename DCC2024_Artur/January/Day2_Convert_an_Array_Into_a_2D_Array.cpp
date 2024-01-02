#include <iostream>
#include "vector"
#include "unordered_map"

using namespace std;

class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int>& nums)
    {
        unordered_map<int, int> map;
        vector<vector<int>> res;
        res.emplace_back();

        for(int val : nums)
        {
            if(map[val] + 1 > res.size())
                res.push_back({val});
            else
                res[map[val]].push_back(val);

            map[val]++;
        }

        return res;
    }
};


int main()
{
    Solution solution;

    vector<int> test = {1,3,4,1,2,3,1};

    vector<vector<int>> res = solution.findMatrix(test);

    for(auto & re : res)
    {
        for(int j : re)
            cout << j << ' ';
        cout << endl;
    }

}