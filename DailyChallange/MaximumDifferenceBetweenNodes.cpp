/*
 https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/solutions/929284/python-o-n-look-at-child-explained/?envType=daily-question&envId=2024-01-11
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
//class Solution {
//public:
//
//    bool findElement(TreeNode* root, int value){
//        if (root == nullptr){
//            return false;
//        }
//        if(root->val == value){
//            return true;
//        }
//        if(root->val < value){
//            return findElement(root->right, value);
//        } else{
//            return findElement(root->left, value);
//        }
//    }
//
//    void findDifference(TreeNode* start, TreeNode* root, int value, int *highestNode){
//        if(root == nullptr){
//            return;
//        }
//
//        if(abs(root->val - value) > *highestNode && findElement(start, abs(root->val - value))){
//            *highestNode = abs(root->val - value);
//        }
//
//
//        findDifference(start, root->left, value, highestNode);
//        if(root->left != nullptr){
//            findDifference(start, root->left, root->val, highestNode);
//        }
//        if(root->right != nullptr){
//            findDifference(start, root->right, root->val, highestNode);
//        }
//    }
//
//
//    int maxAncestorDiff(TreeNode* root) {
//        int highestNode = 0;
//        findDifference(root, root, root->val, &highestNode);
//
//        return highestNode;
//    }
//};

class Solution {
public:
    int findDifference(TreeNode * root, int minimum, int maximum){
        if(root == nullptr){
            return maximum - minimum;
        }
        maximum = max(maximum, root->val);
        minimum = min(minimum, root->val);

        return max(findDifference(root->left, minimum, maximum), findDifference(root->right, minimum, maximum));

    }
    int maxAncestorDiff(TreeNode* root) {
        return findDifference(root, 99990, 0);
    }
};

/*
 Main idea:

 Йдемо з кореня до синів.
 Змінюємо значення максимуму та мінімуму на кожному сині.

 Перевіряємо чи наше значення менше за мінімум, більше за
 максимум, якщо так і є змінюємо значення.
 Передаємо ці значення нашим синам.
 Таким чином для кожної ноди ми отримуємо лише ті значення
 мінімуму та максимуму, що точно були в її батьків.
 */