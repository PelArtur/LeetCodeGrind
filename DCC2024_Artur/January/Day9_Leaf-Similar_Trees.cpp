/*
 https://leetcode.com/problems/leaf-similar-trees/?envType=daily-question&envId=2024-01-09
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
private:
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        vector<int> leafs1;
        vector<int> leafs2;

        postorder(root1, leafs1);
        postorder(root2, leafs2);

        if( leafs1.size() != leafs2.size() )
            return false;

        for(size_t i = 0; i < leafs1.size(); ++i)
            if( leafs1[i] != leafs2[i] )
                return false;

        return true;
    }

    void postorder(TreeNode *node, vector<int> &leafs)
    {
        if ( !node->left && !node->right )
        {
            leafs.push_back(node->val);
            return;
        }
        if ( node->left )
            postorder(node->left, leafs);
        if ( node->right )
            postorder(node->right, leafs);
    }
};


int main()
{
    Solution solution;

    //example 1
    auto* tree1Node7 = new TreeNode(7);
    auto* tree1Node4 = new TreeNode(4);
    auto* tree1Node9 = new TreeNode(9);
    auto* tree1Node8 = new TreeNode(8);
    auto* tree1Node6 = new TreeNode(6);
    auto* tree1Node2 = new TreeNode(2, tree1Node7, tree1Node4);
    auto* tree1Node5 = new TreeNode(5, tree1Node6, tree1Node2);
    auto* tree1Node1 = new TreeNode(1, tree1Node9, tree1Node8);
    auto* tree1Node3 = new TreeNode(3, tree1Node5, tree1Node1);

    auto* tree2Node7 = new TreeNode(7);
    auto* tree2Node4 = new TreeNode(4);
    auto* tree2Node9 = new TreeNode(9);
    auto* tree2Node8 = new TreeNode(8);
    auto* tree2Node6 = new TreeNode(6);
    auto* tree2Node2 = new TreeNode(2, tree1Node9, tree1Node8);
    auto* tree2Node5 = new TreeNode(5, tree1Node6, tree1Node7);
    auto* tree2Node1 = new TreeNode(1, tree1Node4, tree1Node2);
    auto* tree2Node3 = new TreeNode(3, tree1Node5, tree1Node1);

    cout << solution.leafSimilar(tree1Node3, tree2Node3) << endl;

    //example 2
    auto* tree3Node3 = new TreeNode(3);
    auto* tree3Node2 = new TreeNode(2);
    auto* tree3Node1 = new TreeNode(1, tree3Node2, tree3Node3);

    auto* tree4Node3 = new TreeNode(3);
    auto* tree4Node2 = new TreeNode(2);
    auto* tree4Node1 = new TreeNode(1, tree4Node3, tree4Node2);

    cout << solution.leafSimilar(tree3Node1, tree4Node1) << endl;

    return 0;
}

/*
 Main idea:
 Для кожного дерева створюємо масив із значеннями листків.
 Обходимо дерева у зворотньому порядку(ЛПК), коли доходимо до елемента,
 який не має нащадків, тобто листка, додаємо його в масив. Порядок елементів
 у масиві буде корекним, оскільки за даним обходом спершу береться ліва вершина.
 Після обходу обох дерев перевіряються масиви на однакові значення.

 Складність алгоритму: O(n)
 Найскладніша частина алгоритму є обхід дерева, де алгоритм проходиться по всіх
 вершинах дерева. Перевірка на рівність масивів також за O(n).
*/
