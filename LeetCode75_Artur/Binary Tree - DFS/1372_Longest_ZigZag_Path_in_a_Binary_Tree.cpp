/*
 https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/?envType=study-plan-v2&envId=leetcode-75
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
    int longestWay;
public:
    void dfs(TreeNode* root, bool isLeft, int currLen)
    {
        if( !root )
            return;

        if( currLen > longestWay )
            longestWay = currLen;

        if( isLeft )
        {
            dfs(root->right, false, currLen + 1);
            dfs(root->left, true, 1);
        }
        else
        {
            dfs(root->left, true, currLen + 1);
            dfs(root->right, false, 1);
        }
    }

    int longestZigZag(TreeNode* root)
    {
        longestWay = 0;
        dfs(root->left, true, 1);
        dfs(root->right, false, 1);

        return longestWay;
    }
};


int main()
{
    Solution solution;

    auto* tree1Node8 = new TreeNode(1);
    auto* tree1Node7 = new TreeNode(1, nullptr, tree1Node8);
    auto* tree1Node6 = new TreeNode(1);
    auto* tree1Node5 = new TreeNode(1, nullptr, tree1Node7);
    auto* tree1Node4 = new TreeNode(1, tree1Node5, tree1Node6);
    auto* tree1Node3 = new TreeNode(1);
    auto* tree1Node2 = new TreeNode(1, tree1Node3, tree1Node4);
    auto* tree1Node1 = new TreeNode(1, nullptr, tree1Node2);

    auto* tree2Node7 = new TreeNode(1);
    auto* tree2Node6 = new TreeNode(1);
    auto* tree2Node5 = new TreeNode(1, nullptr, tree2Node7);
    auto* tree2Node4 = new TreeNode(1, tree2Node5, tree2Node6);
    auto* tree2Node3 = new TreeNode(1);
    auto* tree2Node2 = new TreeNode(1, nullptr, tree2Node4);
    auto* tree2Node1 = new TreeNode(1, tree2Node2, tree2Node3);

    auto* tree3Node1 = new TreeNode(1);

    cout << solution.longestZigZag(tree1Node1) << endl;
    cout << solution.longestZigZag(tree2Node1) << endl;
    cout << solution.longestZigZag(tree3Node1) << endl;

    return 0;
}

/*
 Main idea:
 Проходимось за допомогою dfs, який має два додаткових параметри:
 - isLeft — чи до цього вузла ми дійшли рухом на ліво;
 - currLen — поточна довжина зігзагу

 Якщо ми пішли до вузла наліво, то для dfs, який піде направо довжина
 зігзагу становитиме на 1 більше і значення isLeft false, для лівого
 сина ситуація буде протилежною. Ми збили зігзаг, тому поточний вузол
 буде першим у новому зігзагу, а його лівий син буде наступним вузлом,
 тому туди передається довжина 1. Для вузла, у якого значення isLeft
 false буде інша, для правого сина значення довжина 1, а для лівого
 поточна довжина +1.

 На кожному виклиці dfs перевіряється чи поточна довжина є більша за
 максимальну, якщо так, то це значення переписується.

 Часова складність алгоритму: O(n).
*/
