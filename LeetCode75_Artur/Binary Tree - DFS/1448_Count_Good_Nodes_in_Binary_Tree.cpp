/*
https://leetcode.com/problems/count-good-nodes-in-binary-tree/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <climits>

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
    int goodNodes(TreeNode* root)
    {
        return dfs(root, INT_MIN);
    }

    int dfs(TreeNode* node, int currMax)
    {
        if(!node)
            return 0;

        int goodNode = 0;
        if(node->val >= currMax)
        {
            goodNode++;
            currMax = node->val;
        }

        return goodNode + dfs(node->left, currMax) + dfs(node->right, currMax);
    }
};


int main()
{
    auto* node1 = new TreeNode(3);
    auto* node2 = new TreeNode(1);
    auto* node3 = new TreeNode(3);
    auto* node4 = new TreeNode(4);
    auto* node5 = new TreeNode(1);
    auto* node6 = new TreeNode(5);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;

    Solution solution;

    cout << solution.goodNodes(node1);
}

/*
  Main idea:
  Пройтись по графу за допомогою dfs, якому окрім вузла
  передається поточний максимум на шляху. Якщо значення
  поточного вузла є більшим або рівним за маскимум, то до
  значення goodNode додається одиниця. Рекурсивно
  повертається сума значень goodNode та обходу dfs дочірніх вузлів.
*/