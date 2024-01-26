/*
 https://leetcode.com/problems/longest-common-subsequence/description/?envType=daily-question&envId=2024-01-25
 */
class Solution {
public:
    int longestCommonSubsequence(string &a, string &b) {
        vector<vector<int>> dp(1001, vector<int> (1001));
        for(int idx = 0; idx < a.size(); ++idx){
            for(int jdx = 0; jdx < b.size(); ++jdx){
                dp[idx + 1][jdx + 1] = a[idx] == b[jdx] ? 1 + dp[idx][jdx] : max(dp[idx + 1][jdx], dp[idx][jdx + 1]);
            }
        }
        return dp[a.size()][b.size()];
    }
};

/*
 Створюємо dp. У ньому зберігаємо максимальну кількість
 підпослідовностей max(a in b, b in a) на поточний крок.
 Якщо відбувається співпадіння чарів, то ми дивимось,
 скільки чарів співпадало між двома послідовностями не
 враховуючи поточний чар, і додаємо до цієї кількості +1
 Якщо чари не співпали, то ми дивимось в якому випадку
 відбулось більше співпадінь: а в б чи б в а і зберігаєм
 цей випадок. Повертаємо останній елемент в матриці, що
 є максимальною кількістю послідовностей.
 */