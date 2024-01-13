/*
 https://leetcode.com/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        if( !root )
            return {};

        vector<int> res;
        deque<TreeNode*> q;
        unordered_map<int, int> len;
        q.push_back(root);
        q.push_back(nullptr);

        TreeNode* curr;
        while( !q.empty() )
        {
            if( q.front() )
            {
                curr = q.front();

                if (curr->left)
                    q.push_back(curr->left);
                if (curr->right)
                    q.push_back(curr->right);

                q.pop_front();
            }
            else
            {
                res.push_back(curr->val);

                q.pop_front();

                if( !q.empty() )
                    q.push_back(nullptr);
            }
        }

        return res;
    }
};


int main()
{
    Solution solution;

    auto* tree1Node5 = new TreeNode(5);
    auto* tree1Node4 = new TreeNode(4);
    auto* tree1Node3 = new TreeNode(3, nullptr, tree1Node4);
    auto* tree1Node2 = new TreeNode(2, nullptr, tree1Node5);
    auto* tree1Node1 = new TreeNode(1, tree1Node2, tree1Node3);

    auto* tree2Node3 = new TreeNode(3);
    auto* tree2Node1 = new TreeNode(1, nullptr, tree2Node3);

    solution.rightSideView(tree1Node1);
    solution.rightSideView(tree2Node1);
}

/*
 Main idea:
 BFS, у якому будемо перевіряти чи рівень завершився, якщо
 він завершився, то додаватимемо останній його елемент в
 масив результату. Для індикації завершення рівня дерева
 в чергу додається nullptr.

 Складність: O(V)
 Кількість ребер залежить від кількості вершин, а саме становить
 V + 1 кількість, для BFS часова складність складає O(V + E), у
 нашому випадку 2V + 1, константи не грають важливої ролі, тому
 загальна часова складність алгоритму: O(V).

 Краще рішення цього завдання:
 
 class Solution {
 public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        rightView(root, view, 0);
        return view;
    }
 private:
    void rightView(TreeNode* root, vector<int>& view, int level) {
        if (!root) {
            return;
        }
        if (view.size() == level) {
            view.push_back(root -> val);
        }
        rightView(root -> right, view, level + 1);
        rightView(root -> left, view, level + 1);
    }
 };

 Рекурсивно за допомогою DFS дерево обходиться в зворонньому порядку,
 перевірка рівня дерева забезпечується збереженням рівня поточного вузла
 в порівнянні з кількості вузлів у результаті, оскільки на один рівень іде
 лише один вузол
*/