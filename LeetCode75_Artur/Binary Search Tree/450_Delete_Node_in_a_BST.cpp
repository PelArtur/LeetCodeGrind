/*
 https://leetcode.com/problems/decode-string/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <string>

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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if( !root || !root->left && !root->right && root->val == key )
            return nullptr;

        TreeNode* parent = root;
        TreeNode* curr = root;

        while(true)
        {
            if(!curr)
                return root;

            if( key < curr->val )
            {
                parent = curr;
                curr = curr->left;
            }
            else if( key > curr->val )
            {
                parent = curr;
                curr = curr->right;
            }
            else
                break;
        }

        TreeNode* newCurr = nullptr;
        if( !curr->left && curr->right )
            newCurr = curr->right;
        else if( curr->left && !curr->right )
            newCurr = curr->left;
        else if( curr->left && curr->right )
        {
            TreeNode* parentNewCurr = curr;
            newCurr = curr->right;
            while(true)
            {
                if( !newCurr->left )
                    break;
                parentNewCurr = newCurr;
                newCurr = newCurr->left;
            }

            if( parentNewCurr->right && newCurr->val == parentNewCurr->right->val )
                parentNewCurr->right = newCurr->right;
            else
                parentNewCurr->left = newCurr->right;

            newCurr->left = curr->left;
            newCurr->right = curr->right;
        }

        if( root->val != key )
        {
            if ( parent->right && curr->val == parent->right->val )
                parent->right = newCurr;
            else
                parent->left = newCurr;
        }
        else
            root = newCurr;

        delete curr;
        return root;
    }
};


int main()
{
    Solution solution;

    auto* tree1Node2 = new TreeNode(2);
    auto* tree1Node4 = new TreeNode(4);
    auto* tree1Node7 = new TreeNode(7);
    auto* tree1Node3 = new TreeNode(3, tree1Node2, tree1Node4);
    auto* tree1Node6 = new TreeNode(6, nullptr, tree1Node7);
    auto* tree1Node5 = new TreeNode(5, tree1Node3, tree1Node6);

    auto* tree2Node7 = new TreeNode(7);
    auto* tree2Node15 = new TreeNode(15);
    auto* tree2Node8 = new TreeNode(8, tree2Node7, nullptr);
    auto* tree2Node10 = new TreeNode(10, tree2Node8, tree2Node15);
    auto* tree2Node4 = new TreeNode(4);
    auto* tree2Node5 = new TreeNode(5, tree2Node4, tree2Node10);
    auto* tree2Node2 = new TreeNode(2);
    auto* tree2Node3 = new TreeNode(3, tree2Node2, tree2Node5);

    cout << solution.deleteNode(tree1Node5, 5);
    cout << solution.deleteNode(tree2Node3, 5);
}

/*
 Main idea:
 Коли видаляється вузол може виникнути три випадки:
 - у вузла немає синів — просто видаляємо це вузол, присвоївши на
   його місце nullptr у батька
 - У вузла лише 1 син — заміняємо цей вузол на його сина
 - У вузла 2 сина — спершу шукаємо наступного за значенням сина, у
   якого немає лівого сина.

 Якщо ж значення видаленого вузла немає в дереві, то нічого не робимо.

 Складність алгоритму: O(logn)
*/