/*
 https://leetcode.com/problems/find-peak-element/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int>& nums)
    {
        if( nums.size() == 1 )
            return 0;

        if( nums[0] > nums[1] )
            return 0;
        if( nums[nums.size() - 1] > nums[nums.size() - 2])
            return (int) nums.size() - 1;

        int l = 1;
        int r = (int) nums.size() - 2;
        int mid;
        while(l < r)
        {
            mid = l + (r - l) / 2;
            if( nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                return mid;
            else if( nums[mid] < nums[mid + 1] )
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1,2,3,1};
    vector<int> test2 = {1,2,1,3,5,6,4};

    cout << solution.findPeakElement(test1) << endl;
    cout << solution.findPeakElement(test2) << endl;
}

/*
 Main idea:
 Простий бінарний пошук, але шукаємо такий елемент, що числа
 перед ним та після нього є меншими.
 На початку перевіряємо 3 крайні випадки, коли пік на початку,
 коли в кінці і коли масив має лише 1 елемент.

 Складність алгоритму: O(logn).

 Проте по фактичному часу алгоритм з лінійним час є не гіршим,
 моментами навіть кращий

 class Solution
 {
 public:
    int findPeakElement(vector<int>& nums)
    {
        int maxInd = 0;
        int maxVal = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            if( nums[i] > maxVal )
            {
                maxInd = i;
                maxVal = nums[i];
            }

        return maxInd;
    }
 };

 Тут шукається просто максимум, бо він завжди є піком,
 можна й не проходити весь масив, спершу зрозумів умову
 неправильно
*/