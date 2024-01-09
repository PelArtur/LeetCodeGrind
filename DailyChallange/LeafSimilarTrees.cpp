/*
 https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09
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
    vector<int> leafSequence;
    int idx = 0;

    void findLeafs(TreeNode* root){
        if(root != nullptr){
            findLeafs(root->left);
            if(root->left == nullptr && root->right == nullptr){
                leafSequence.push_back(root->val);
            }
            findLeafs(root->right);
        }
    }

    bool compareLeaves(TreeNode* root){
        bool result = true;
        if(root != nullptr){
            result = compareLeaves(root->left);
            if(root->left == nullptr && root->right == nullptr && result == true){
                if (leafSequence[idx] != root->val){
                    return false;
                }
                idx++;
            }
            result = result == false ? false : compareLeaves(root->right);
        }
        return result;
    }


    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        findLeafs(root1);
        return compareLeaves(root2) && idx == leafSequence.size();

    }
};


/*
 Main idea:

 Створюєм список листків. Спочатку додаємо туди листки
 першого дерева, викликаєм таку ж функцію для другого
 дерева, тільки тепер не додаємо листок, а перевіряємо
 чи відповідний листок за індексом дорівнює нашому листку.
 Якщо так, збільшуємо індекс для наступної перевірки.
 Якщо ні, повертаєм false.
 Повертаємо результат другої функції і idx == vectorOne.size()
 з метою перевірити, чи однакова кількість листків.
 */