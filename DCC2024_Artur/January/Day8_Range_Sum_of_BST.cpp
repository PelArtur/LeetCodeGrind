/*
 https://leetcode.com/problems/range-sum-of-bst/?envType=daily-question&envId=2024-01-08
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


class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        return postorder(root, low, high);
    }


    int postorder(TreeNode *node, int low, int high)
    {
        int res = 0;
        if( node->left )
            res += postorder(node->left, low, high);
        if( node->right )
            res += postorder(node->right, low, high);
        if( low <= node->val && node->val <= high )
            res += node->val;

        return res;
    }
};


int main()
{
    Solution solution;

    auto* node1 = new TreeNode(1);
    auto* node6 = new TreeNode(6);
    auto* node3 = new TreeNode(3, node1, nullptr);
    auto* node7 = new TreeNode(7, node6, nullptr);
    auto* node13 = new TreeNode(13);
    auto* node18 = new TreeNode(18);
    auto* node5 = new TreeNode(5, node3, node7);
    auto* node15 = new TreeNode(15, node13, node18);
    auto* node10 = new TreeNode(10, node5, node15);

    cout << solution.rangeSumBST(node10, 10, 18) << endl;

    return 0;
}

/*
 Main idea:
 Обходимо дерева у зворотньому порядку(ЛПК), на кожній рекурсивній
 ітерації повертається сума значень лівого, правого сина, а також
 кореня, якщо його значення входить в даний інтервал.
*/
