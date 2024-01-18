/*
 https://leetcode.com/problems/number-of-provinces/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<bool> visited;
    int n;
public:
    void dfs(int root, vector<vector<int>>& isConnected)
    {
        for(int i = 0; i < n; ++i)
        {
            if( isConnected[root][i] && !visited[i] )
            {
                visited[i] = true;
                dfs(i, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected)
    {
        n = (int) isConnected.size();
        visited = vector<bool>(n, false);
        int provincesNum = 0;
        for(int i = 0; i < n; ++i)
        {
            if( !visited[i] )
            {
                visited[i] = true;
                dfs(i, isConnected);
                provincesNum++;
            }
        }

        return provincesNum;
    }
};


int main()
{
    Solution solution;

    vector<vector<int>> test1 = {{1,1,0},{1,1,0},{0,0,1}};
    vector<vector<int>> test2 = {{1,0,0},{0,1,0},{0,0,1}};

    cout << solution.findCircleNum(test1) << endl;
    cout << solution.findCircleNum(test2) << endl;
}

/*
 Main idea:
 В загальній функції запускаємо dfs для всіх непройдених
 вершин і рахуємо кількість цих запусків, тоді отримуємо
 загальну кількість провінцій.

 Часова складність: O(n^2)
 Для кожної вершини перевіряється суміжність і відвіданість
 інших вершин.
*/