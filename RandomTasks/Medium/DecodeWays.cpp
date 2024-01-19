/*
 https://leetcode.com/problems/decode-ways/
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int strSize = s.size();
        vector<int> dp (strSize + 1);
        dp[strSize] = 1;
        for(int idx = strSize - 1; idx >= 0; --idx){
            if(s[idx] == '0'){
                dp[idx] = 0;
            } else {
                dp[idx] += dp[idx + 1];
                if((s[idx] == '1' || s[idx] == '2' && s[idx + 1] < '7') && (idx < strSize - 1)){
                    dp[idx] += dp[idx + 2];
                }
            }
        }
        return s.empty() ? 0 : dp[0];
    }
};


/*
 Main idea:

 idx + 1 рахує кількість кодувань, які вже можуть бути здійснені
 не враховуючи поточний символ
 idx + 2 додає кількість кодувань, які створяться за рахунок
 врахування різних способів декодування поточного символу
 Повертаємо всі можливі декодування
 */