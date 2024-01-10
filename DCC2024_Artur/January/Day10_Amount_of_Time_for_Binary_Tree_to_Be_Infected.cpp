/*
 https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
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
public:
    int amountOfTime(TreeNode* root, int start) {

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


    return 0;
}

/*
 Main idea:
*/
