/*
 https://leetcode.com/problems/range-sum-of-bst/?envType=daily-question&envId=2024-01-08
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int result = 0;

    void inorder(TreeNode* root, int low, int high){
        if(root){
            inorder(root->left, low, high);
            if(root->val >= low && root->val <= high){
                result+= root->val;
            }
            inorder(root->right, low, high);
        }
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return result;

    }
};

/*
 Main idea:

 Проходимось по всьому дереву, додаємо елемент лише якщо
 він за значенням у нашому ренджі.
 */