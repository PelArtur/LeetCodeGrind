/*
 https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11
*/

#include <iostream>
#include <vector>

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
private:
    int maxDiff;

public:
    int maxAncestorDiff(TreeNode* root)
    {
        maxDiff = 0;
        preorder(root);

        return maxDiff;
    }

    pair<int, int> preorder(TreeNode* root)
    {
        int currMin = root->val;
        int currMax = root->val;

        if( !root->left && !root->right )
            return make_pair(currMin, currMax);

        if( root->left )
        {
            auto left = preorder(root->left);
            maxDiff = max(maxDiff, abs(root->val - left.first));
            maxDiff = max(maxDiff, abs(root->val - left.second));
            currMin = min(currMin, left.first);
            currMax = max(currMax, left.second);
        }
        if( root->right )
        {
            auto right = preorder(root->right);
            maxDiff = max(maxDiff, abs(root->val - right.first));
            maxDiff = max(maxDiff, abs(root->val - right.second));
            currMin = min(currMin, right.first);
            currMax = max(currMax, right.second);
        }

        return make_pair(currMin, currMax);
    }
};

int main()
{
    auto *solution = new Solution();

    auto* node4 = new TreeNode(4);
    auto* node7 = new TreeNode(7);
    auto* node1 = new TreeNode(1);
    auto* node13 = new TreeNode(13);
    auto* node6 = new TreeNode(6, node4, node7);
    auto* node14 = new TreeNode(14, node13, nullptr);
    auto* node3 = new TreeNode(3, node1, node6);
    auto* node10 = new TreeNode(10, nullptr, node14);
    auto* node8 = new TreeNode(8, node3, node10);
    cout << solution->maxAncestorDiff(node8) << endl;

    auto* node03 = new TreeNode(3);
    auto* node00 = new TreeNode(0, node03, nullptr);
    auto* node02 = new TreeNode(2, nullptr, node00);
    auto* node01 = new TreeNode(1, nullptr, node02);
    cout << solution->maxAncestorDiff(node01) << endl;

    delete solution;
    return 0;
}

/*
 Main idea:
 Зробити обхід дерева, на кожному кроці отримуємо мінімальне
 та максимальне значення правого та лівого піддерева. Перевіряємо
 чи поточний максимум є менший/більший

 Складність O(N): postorder
*/
