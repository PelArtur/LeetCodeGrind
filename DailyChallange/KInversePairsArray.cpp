/*
https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27
 */
class Solution {
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k) {
        if (k <= 0)
            return k == 0;
        if (dp[n][k] == 0) {
            dp[n][k] = 1;
            for (auto i = 0; i < n; ++i) {
                dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
            }
        }
        return dp[n][k] - 1;
    }
};

/*
 Main idea:

 Write in future here!
 */