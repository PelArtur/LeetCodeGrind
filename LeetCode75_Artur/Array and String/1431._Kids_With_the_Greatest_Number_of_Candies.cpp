#include <iostream>
#include "vector"

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector<bool> res = vector<bool>(candies.size(), false);
        int max = 0;
        for(int candy : candies)
            if (candy > max)
                max = candy;

        for(size_t i = 0; i < candies.size(); ++i)
            if(candies[i] + extraCandies >= max)
                res[i] = true;

        return res;
    }
};