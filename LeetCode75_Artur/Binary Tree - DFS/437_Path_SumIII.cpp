/*
 https://leetcode.com/problems/path-sum-iii/submissions/1148731970/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <unordered_map>
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
    int pathNum;

public:
    void dfs(TreeNode* root, long long targetSum)
    {
        if( !root )
            return;

        if( root->val == targetSum )
            pathNum++;

        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

    }

    void pathSumRec(TreeNode* root, long long targetSum)
    {
        if( root )
        {
            dfs(root, targetSum);
            pathSumRec(root->left, targetSum);
            pathSumRec(root->right, targetSum);
        }
    }

    int pathSum(TreeNode* root, int targetSum)
    {
        pathNum = 0;
        pathSumRec(root, targetSum);
        return pathNum;
    }
};


int main()
{
    Solution solution;

    //example 1
    auto* tree1Node1 = new TreeNode(1);
    auto* tree1Nodem2 = new TreeNode(-2);
    auto* tree1Node_3 = new TreeNode(3);
    auto* tree1Node11 = new TreeNode(11);
    auto* tree1Node2 = new TreeNode(2, nullptr, tree1Node1);
    auto* tree1Node3 = new TreeNode(3, tree1Node_3, tree1Nodem2);
    auto* tree1Nodem3 = new TreeNode(-3, nullptr, tree1Node11);
    auto* tree1Node5 = new TreeNode(5, tree1Node3, tree1Node2);
    auto* tree1Node10 = new TreeNode(10, tree1Node5, tree1Nodem3);

    auto* tree2Node1 = new TreeNode(1);
    auto* tree2Node_5 = new TreeNode(5);
    auto* tree2Node2 = new TreeNode(2);
    auto* tree2Node7 = new TreeNode(7);
    auto* tree2Node_4 = new TreeNode(4, tree2Node_5, tree2Node1);
    auto* tree2Node13 = new TreeNode(13);
    auto* tree2Node11 = new TreeNode(11, tree2Node7, tree2Node2);
    auto* tree2Node8 = new TreeNode(8, tree2Node13, tree2Node_4);
    auto* tree2Node4 = new TreeNode(4, tree2Node11, nullptr);
    auto* tree2Node5 = new TreeNode(5, tree2Node4, tree2Node8);

    auto* tree3Node5 = new TreeNode(5);
    auto* tree3Node4 = new TreeNode(4, tree3Node5, nullptr);
    auto* tree3Node3 = new TreeNode(3, tree3Node4, nullptr);
    auto* tree3Node2 = new TreeNode(2, tree3Node3, nullptr);
    auto* tree3Node1 = new TreeNode(1, tree3Node2, nullptr);

    cout << solution.pathSum(tree1Node10, 8) << endl;
    cout << solution.pathSum(tree2Node5, 22) << endl;
    cout << solution.pathSum(tree3Node1, 3) << endl;

    return 0;
}

/*
 Main idea:
 Два рази проганяти dfs:
 Зовнішній: щоразу рухаємось вниз і запускаємо внутрішній dfs з
 пошуком очікуваної суми починаючи з певного вузла.
 Внутрішній: запускається починаючи з вершини, з якої викликається у
 зовнішньому dfs, на кожному кроці перевіряємо чи очікувана сума є рівною
 значенню вершини і запускаємо дальше обхід, зменшуючи очікуючу суму.

 Часова складність алгоритму: O(n^2)
*/
