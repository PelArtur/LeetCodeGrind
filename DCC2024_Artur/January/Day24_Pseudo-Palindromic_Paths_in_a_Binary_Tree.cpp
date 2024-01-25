/*
 https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
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
        int pathsNum;
    public:
        void dfs(TreeNode* root, vector<int> occurrence)
        {
            if( !root )
                return;

            occurrence[root->val - 1]++;

            if( !root->left && !root->right )
            {
                int len = 0;
                int oddsNum = 0;
                for(auto occurr : occurrence)
                {
                    len += occurr;
                    if( occurr % 2)
                        oddsNum++;
                }

                if( oddsNum < 2 )
                    pathsNum++;

                return;
            }

            dfs(root->left, occurrence);
            dfs(root->right, occurrence);
        }

        int pseudoPalindromicPaths(TreeNode* root)
        {
            pathsNum = 0;
            auto occurrence = vector<int>(9, 0);
            dfs(root, occurrence);
            return pathsNum;
        }
    };


int main()
{
    Solution solution;

    auto* tree1Node6 = new TreeNode(1);
    auto* tree1Node5 = new TreeNode(1);
    auto* tree1Node4 = new TreeNode(3);
    auto* tree1Node3 = new TreeNode(3, tree1Node4, tree1Node5);
    auto* tree1Node2 = new TreeNode(1, nullptr, tree1Node6);
    auto* tree1Node1 = new TreeNode(2, tree1Node3, tree1Node2);

    auto* tree2Node6 = new TreeNode(1);
    auto* tree2Node5 = new TreeNode(3, nullptr, tree2Node6);
    auto* tree2Node4 = new TreeNode(1);
    auto* tree2Node3 = new TreeNode(1);
    auto* tree2Node2 = new TreeNode(1, tree2Node4, tree2Node5);
    auto* tree2Node1 = new TreeNode(2, tree2Node2, tree2Node3);

    auto* tree3Node1 = new TreeNode(9);

    cout << solution.pseudoPalindromicPaths(tree1Node1) << endl;
    cout << solution.pseudoPalindromicPaths(tree2Node1) << endl;
    cout << solution.pseudoPalindromicPaths(tree3Node1) << endl;
}

/*
 Main idea:
 Щоб зо якоїсь послідовності чисел/букв зробити паліндром необхідно,
 щоб значень, які зустрічаються непарну кількість раз у цій послідовності
 було не більше, ніж 1, в іншому випадку не вийде скласти паліндром.

 Наприклад:
 12321 - у цій послідовності 3 зустрічається один раз, інші символи по два,
 тому 3 можна поставити лише в середину паліндрома, а інші числа рівномірно
 відносно неї.
 1221 - у цій послідовності немає непарних входжень.
 123421 - тут є два числа, які зустрічаються напарну кількість раз і як би
 вони не переставлялись, паліндром побудувати неможливо.

 Отже, ідея цього алгоритму в тому, щоб пройтись одним шляхом, рахуючи кількість
 входжень кожного значення і якщо цей шлях містить 0 або 1 таке число, яке зустрічається
 непарну кількість раз, тоді можна побудувати паліндром(окрім випадку, коли послідовність
 пуста) і до результату додається один.

 Щоб пройтись по шляхах використовується dfs.

 Часова складність алгоритму: O(n).
*/