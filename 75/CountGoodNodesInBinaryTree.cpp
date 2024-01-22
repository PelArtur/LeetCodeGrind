/*
 https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
    int goodNodesCounter(TreeNode* root, int maxDepth){
        if(root == nullptr){
            return 0;
        }
        if(root->val >= maxDepth){
            maxDepth = root->val;
            return 1 + goodNodesCounter(root->left, maxDepth) + goodNodesCounter(root->right, maxDepth);
        } else {
            return goodNodesCounter(root->left, maxDepth) + goodNodesCounter(root->right, maxDepth);
        }
    }

    int goodNodes(TreeNode* root) {
        return goodNodesCounter(root, -10001);
    }
};

/*
 Main idea:

 Створюємо рекурсію.
 Викликаємо рекурсію до самого кореня.
 Протягом того як ми йдемо до кореня,
 зберігаємо найбільше значення, що було
 на шляху. Якщо поточне значення більше
 ніж найбільше, що зустрічалось, то це
 означає що ми можемо додати цей елемент
 у список хороших нод. Повертаємо 1 і
 результат виклику функції для наших
 синів. Якщо значення ноди хороше, то ми
 додаємо до результату 1 і результа наших
 синів, а якщо погане то додаємо до лише
 результат наших синів.

 Ось це +1 і буде рахувати кількість хороших
 нод.
 Base case:
 Нода це Nullptr. Таким чином ніякого
 значення в неї нема, тому повертаємо 0.
 */