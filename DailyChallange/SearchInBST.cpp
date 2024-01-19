/*
 https://leetcode.com/problems/search-in-a-binary-search-tree/description/?envType=study-plan-v2&envId=leetcode-75
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return root;
        }

        if(root->val == val){
            return root;
        }

        if(root->val > val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
};



/*
 Main idea:

 Запускаємо рекурсію

 Base case:
 Нода не інсує, тобто nullptr.
 Значить немає такого значення, повертаємо nullptr.

 Base case:
 Значення ноди дорівнює шуканому
 Ми знайшли значення і повертаємо ноду

 Якщо поточне значення більше, ніж ми шукаємо, то ми йдемо
 в лівих синів, оскільки там лише більші значення
 Якщо поточне значення менше, то ми йдемо в праві сини,
 оскільки там значення більші за поточне

 */