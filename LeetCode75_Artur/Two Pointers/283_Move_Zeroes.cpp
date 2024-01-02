#include <iostream>
#include "vector"

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int curr = 0;
        int i = curr;
        int j = (int) nums.size() - 1;

        while(i < j)
        {
            if(nums[i])
                i++;
            else
            {
                curr = i;
                while(curr < j)
                {
                    swap(nums[curr], nums[curr + 1]);
                    curr++;
                }
                j--;
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<int> test = {0,0,1};
    solution.moveZeroes(test);
}