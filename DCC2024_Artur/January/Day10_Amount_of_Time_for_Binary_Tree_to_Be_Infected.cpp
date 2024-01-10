/*
 https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution
{
public:
    int time;
    unordered_map<int, vector<int>> graph;

public:
    int amountOfTime(TreeNode* root, int start)
    {
        graph.clear();
        time = 0;
        convertToUndirected(root);
        bfs(start);

        return time;
    }

    void convertToUndirected(TreeNode* node)
    {
        if( !node )
            return;

        if( node->right )
        {
            graph[node->val].push_back(node->right->val);
            graph[node->right->val].push_back(node->val);
            convertToUndirected(node->right);
        }
        if( node->left )
        {
            graph[node->val].push_back(node->left->val);
            graph[node->left->val].push_back(node->val);
            convertToUndirected(node->left);
        }
    }

    void bfs(int start)
    {
        queue<int> q;
        unordered_map<int, int> visited;
        unordered_map<int, int> dist;

        q.push(start);
        visited[start] = 1;
        dist[start] = 0;

        int currNode;
        while( !q.empty() )
        {
            currNode = q.front();
            q.pop();
            for(auto neigh : graph[currNode])
            {
                if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = 1;
                    dist[neigh] = dist[currNode] + 1;
                }
            }
        }

        time = dist[currNode];
    }
};

int main()
{
    Solution solution;

    auto* node2 = new TreeNode(9);
    auto* node9 = new TreeNode(2);
    auto* node6 = new TreeNode(6);
    auto* node10 = new TreeNode(10);
    auto* node4 = new TreeNode(4, node9, node2);
    auto* node3 = new TreeNode(3, node10, node6);
    auto* node5 = new TreeNode(5, nullptr, node4);
    auto* node1 = new TreeNode(1, node5, node3);


    auto* node15 = new TreeNode(5);
    auto* node14 = new TreeNode(4, nullptr, node15);
    auto* node13 = new TreeNode(3, nullptr, node14);
    auto* node12 = new TreeNode(2, nullptr, node13);
    auto* node11 = new TreeNode(1, nullptr, node12);


    auto* node25 = new TreeNode(5);
    auto* node24 = new TreeNode(4);
    auto* node23 = new TreeNode(3, nullptr, node25);
    auto* node22 = new TreeNode(2, node23, node24);
    auto* node21 = new TreeNode(1, nullptr, node22);

    cout << solution.amountOfTime(node1, 3) << endl;
    cout << solution.amountOfTime(node11, 4) << endl;
    cout << solution.amountOfTime(node21, 4) << endl;
    return 0;
}

/*
 Main idea:
 Перетворити дерево на undirected граф. Пройтись цим графом за допомогою
 bfs, рахуючи шлях, до кожної вершини. Наш кінцевий шлях буде шляхом до
 останньої пройдеоної вершини за допомогою bfs.

 Складність O(V + E)
*/
