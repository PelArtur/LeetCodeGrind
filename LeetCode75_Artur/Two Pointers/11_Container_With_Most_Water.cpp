/*
 https://leetcode.com/problems/container-with-most-water/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int left = 0;
        int right = (int) height.size() - 1;

        int width = (int) height.size() - 1;
        int currVolume;
        int currMax = 0;

        while( left < right )
        {
            currVolume = width * min(height[left], height[right]);
            currMax = max(currVolume, currMax);

            if( height[left] > height[right] )
                right--;
            else
                left++;
            width--;
        }

        return currMax;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1,8,6,2,5,4,8,3,7};
    vector<int> test2 = {1,1};

    cout << solution.maxArea(test1) << endl;
    cout << solution.maxArea(test2) << endl;
}

/*
 Main idea:
 Є два поінтера, один на початку масиву, один в кінці,
 вони відповідають за межі контейнера. Кожного разу посуваємо
 до центру той поінтер, значення на якому є менше, щоб
 максимізувати об'єм.

 Складність роботи алгоритму: O(n)
*/