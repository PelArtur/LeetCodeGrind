/*
 https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/?envType=daily-question&envId=2024-01-10
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

struct TreeNode {
          int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

#include <vector>
#include <map>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:

    map<int,  vector<int>> graph;

    void createGraph(TreeNode* root){
        queue<pair<TreeNode*, int>> treeQueue;

        treeQueue.push(make_pair(root, -1));

        while(!treeQueue.empty()){
            auto node = treeQueue.front();
            treeQueue.pop();

            if(node.second != -1){
                graph[node.first->val].push_back(node.second);
            }

            if(node.first->left != nullptr){
                graph[node.first->val].push_back(node.first->left->val);
                treeQueue.push(make_pair(node.first->left, node.first->val));
            }
            if(node.first->right != nullptr){
                graph[node.first->val].push_back(node.first->right->val);
                treeQueue.push(make_pair(node.first->right, node.first->val));
            }

        }

    }

    int amountOfTime(TreeNode* root, int start) {
        createGraph(root);
        int frontElement;
        int counter = -1;

        queue<int> order;
        map<int, int> used;

        order.push(start);
        used[start] = 1;

        while(!order.empty()){
            int orderSize = order.size();
            counter++;
            for(int i = 0; i < orderSize; ++i){
                frontElement = order.front();
                vector<int> * graphPointer = &graph[frontElement];
                for(int idx = 0; idx < (*graphPointer).size(); idx++){
                    if(used[(*graphPointer)[idx]] == 0){
                        order.push((*graphPointer)[idx]);
                        used[(*graphPointer)[idx]] = 1;
                    }
                }
                order.pop();
            }
        }

        return counter;
    }
};



/*
 Main idea:

 Спочатку перетворюємо дерево в орієнтований граф.

 Робимо це наступним чином:
 створюємо мапу з ключами вершинами,значеннями будуть
 вершини в які можна дістатись з цих вершин.
 Йдучи по дереву для ноди зберігаємо її батька.
 Додаємо в мапу ноду її синів і батька.
 Повторюємо цей процес циклічно.

 З утвореним графом робим наступне.
 Починаємо з стартової точки. Додаємо в результат +1
 Всі елементи стартової точки додаємо в чергу. Зберігаємо
 розмір цієї черги.
 Наступної ітерації додаємо +1 в результат. Для кожного елемента
 зберігаємо його дотичні елементи. Якщо ми ще були в цьому елементі,
 додаємо його в чергу.
 */