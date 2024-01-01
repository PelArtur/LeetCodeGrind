#include <iostream>
#include <vector>

using namespace std;

    class Solution
    {
    public:
        vector<int> countBits(int n)
        {
            vector<int> res = vector<int>(n+1, 0);

            for(int i = 1; i <= n; ++i)
                res[i] = res[i >> 1] + (i & 1);

            return res;
        }
    };

int main()
{
    Solution test;
    int n = 16;
    vector<int> uuu = test.countBits(n);

    cout << '[' << uuu[0];
    for(int i = 1; i <= n; ++i)
        cout << ", " << uuu[i];
    cout << ']' << endl;
}
