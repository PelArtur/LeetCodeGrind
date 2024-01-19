/*
 https://leetcode.com/problems/max-consecutive-ones-iii/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestOnes(vector<int>& nums, int k)
    {
        int numZeros = 0;
        int numOnes = 0;
        int maxOnes = 0;

        int left = 0;
        int right = 0;
        while( right < nums.size() )
        {
            if( nums[right++] )
                numOnes++;
            else
                numZeros++;

            while( numZeros > k )
            {
                if( nums[left] )
                    numOnes--;
                else
                    numZeros--;
                left++;
            }

            maxOnes = max(maxOnes, numOnes + numZeros);
        }

        return maxOnes;
    }
};


int main()
{
    Solution solution;

    vector<int> test1 = {1,1,1,0,0,0,1,1,1,1,0};
    vector<int> test2 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};

    cout << solution.longestOnes(test1, 2) << endl;
    cout << solution.longestOnes(test2, 3) << endl;
}

/*
 Main idea:
 Є два поінтери, які обмежують підпослідовність, яка
 має щонайбільше k нулів. Якщо нулів є більше за k,
 то сунемо лівий поінтер до тих пір, поки нулів не буде
 рівно k.

 Рахуємо кількість нулів та одиниць у підпослідовності,
 якщо нулів є щонайбільше k, то порівнюємо максимальну
 кількість із кількістю елементів у цій підпослідовності.

 Часова складність алгоритму: O(n)
*/