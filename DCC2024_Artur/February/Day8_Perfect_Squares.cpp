/*
 https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n)
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; ++i)
            for(int j = 1; j * j <= i; ++j)
                dp[i] = min(dp[i], dp[i - j*j] + 1);

        return dp[n];
    }
};


int main()
{
    cout << Solution().numSquares(12) << endl;
    cout << Solution().numSquares(13) << endl;
}

/*
 Main idea:
 DP. Ідея полягає в тому, щоб рахувати для кожного
 числа до n мінімальну кількість сум квадратів. Обрахунок
 відбувається так, для кожного і числа перевіряються всі
 числа, квадрат яких є меншим за і, після чого вважаємо, що
 цей квадрат є в сумі і тоді потрібно додати ще n квадратів,
 тому дивимось на число, якого не хватає в сумі, тобто i - j^2,
 і до 1 додаємо кількість квадратів цього числа, якщо ця кількість
 буде меншою за поточний мінімум, то перезаписуємо його.
*/