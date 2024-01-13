/*
 https://leetcode.com/problems/binary-tree-right-side-view/description/
 */

#include <vector>

using namespace std;

class Solution {
private:
    vector<int> rightNodes;
    int maxHeight = -1;
public:

    void recursive(TreeNode* root, int height){
        if(root == nullptr){
            return;
        }

        if(height > maxHeight){
            maxHeight = height;
            rightNodes.push_back(root->val);
        }

        recursive(root->right, height + 1);
        recursive(root->left, height + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        recursive(root, 0);
        return rightNodes;
    }
};

/*
 https://leetcode.com/problems/binary-tree-right-side-view/solutions/4558289/simple-recursive-c-approach-o-n

 Зберігаємо висоту для кожної ноди.
 Якщо висота поточної ноди більша ніж максимальна,
 то додаємо значення ноди до результату.
 Це працює за рахунок того, що ми спочатку обходимо
 праве піддерево, таким чином висота спочатку збільшується
 для правих нод, тому вони швидше потрапляють в результат і
 збільшують максимальну висоту, яка була досягнута. А ліві
 ноди збільшують свою висоту пізніше, тому не потрапляють у
 результат, якщо мають меншу висоту, а якщо мають більшу, то це значить
 що вони нижче ніж найнижча права висота і можуть бути додані.
 */