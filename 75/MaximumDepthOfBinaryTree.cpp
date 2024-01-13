/*
 https://leetcode.com/problems/maximum-depth-of-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};


/*
 Main idea:

 Робим цю таску рекурсивно.

 На кожному кроці перевіряємо чи поточна нода існує,
 якщо існує додаємо одиницю до висоти і запускаєм цей
 алгоритм для дочірніх нод. Якщо не існує, то дерево
 закінчилось і ми повертаємо одиничку. В іншому випадку
 повертаємо максимум між лівою та правою нодами щоб знайти
 максимальну висоту між синами.


 Таким чином ми точно враховуєм поточну ноду, оскільки нам
 потрібно знайти максимальну ноду то ми маємо знайти максимальну висоту під нами.
 Для цього нам варто порівняти, що має більшу висоту, правий син чи лівий. Тому беремо
 максимум.
 */