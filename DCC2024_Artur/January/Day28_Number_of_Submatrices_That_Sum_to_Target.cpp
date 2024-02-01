/*
 https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/submissions/1159334050/?envType=daily-question&envId=2024-01-28
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int rows = (int) matrix.size();
        int cols = (int) matrix[0].size();

        auto subSum = vector<vector<int>>(rows, vector<int>(cols, 0));
        subSum[0][0] = matrix[0][0];

        for(int i = 1; i < cols; ++i)
            subSum[0][i] = subSum[0][i - 1] + matrix[0][i];

        for(int j = 1; j < rows; ++j)
            subSum[j][0] = subSum[j - 1][0] + matrix[j][0];

        int top, left, topLeft;
        for(int row = 1; row < rows; ++row)
        {
            for(int col = 1; col < cols; ++col)
            {
                top = subSum[row - 1][col];
                left = subSum[row][col - 1];
                topLeft = subSum[row - 1][col - 1];
                subSum[row][col] = matrix[row][col] + top + left - topLeft;
            }
        }

        int res = 0;
        for(int row1 = 0; row1 < rows; ++row1)
            for(int row2 = row1; row2 < rows; ++row2)
                for(int col1 = 0; col1 < cols; ++col1)
                    for(int col2 = col1; col2 < cols; ++col2)
                    {
                        top = row1 > 0 ? subSum[row1 - 1][col2] : 0;
                        left = col1 > 0 ? subSum[row2][col1 - 1] : 0;
                        topLeft = min(row1, col1) > 0 ? subSum[row1 - 1][col1 - 1] : 0;
                        if( subSum[row2][col2] - top - left + topLeft == target )
                            res++;
                    }

        return res;
    }
};


int main()
{
    vector<vector<int>> test1 = {{0,1,0},{1,1,1},{0,1,0}};
    vector<vector<int>> test2 = {{1,-1},{-1,1}};
    vector<vector<int>> test3 = {{904}};

    cout << Solution().numSubmatrixSumTarget(test1, 0) << endl;
    cout << Solution().numSubmatrixSumTarget(test2, 0) << endl;
    cout << Solution().numSubmatrixSumTarget(test3, 0) << endl;
}

/*
 Main idea:
 https://www.youtube.com/watch?v=43DRBP2DUHg

 Часова складність: O(m^2 + n^2)
*/