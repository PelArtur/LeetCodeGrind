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
//    struct distanceInfo {
//        int distToInf = 0;
//        int length = 0;
//    };
//
//    distanceInfo findTime(TreeNode* root, int start, int& time) {
//        distanceInfo result;
//        if (!root)
//            return result;
//
//        distanceInfo left = findTime(root->left, start, time);
//        distanceInfo right = findTime(root->right, start, time);
//
//        if(root->val == start){
//            result.distToInf = 1;
//            time = max(left.length, right.length);
//            return result;
//        }
//
//        if(left.distToInf == 0 && right.distToInf == 0){
//            result.length = max(left.length, right.length) + 1;
//            return result;
//        }
//
//        if(left.distToInf > 0){
//            time = max(time, left.distToInf + right.length);
//            result.distToInf = left.distToInf + 1;
//            return result;
//        }
//
//
//        if(right.distToInf > 0){
//            time = max(time, right.distToInf + left.length);
//            result.distToInf = right.distToInf + 1;
//            return result;
//        }
//
//    }
//
//    int amountOfTime(TreeNode* root, int start) {
//        int time = 0;
//        findTime(root, start, time);
//        return time;
//    }
//
//};

/*
 Main idea:
 
 неймовірний розв'язок, сам до нього додумався але не зміг 
 реалізувати - після брутфорсу знайшов його на літкоді
 
 Ідея наступна
 
 Ділимо задачу пошуку часу на дві підзадачі:
 1. Знайти час, що потрібно для того щоб заразити всіх синів
 нашої зараженої ноди.
 2. Знайти час, що потрібно для того щоб дойти до найглибшого
 шляху від нашої ноди.
 
 
 Перша задача розв'язується таким чином:
 поки не знайдемо заражену ноду маркуємо довжину нашого шляху
 як глибину(Length) цієї ноди + 1 (підняття до батька)
 Коли знаходимо заражену - сетаєм час як максимум з довжин лівої
 або правої
 
 Друга задача розв'язується таким чином:
 Один з наших синів має дистанцію до зараженої ноди.
 До прикладу, дистанція визначає розмір шляху до
 зараженої яка є в лівому піддереві.
 Така ситуація: нам потрібно дійти від зараженої
 ноди до поточної ноди(це робиться за довжину до зараженої ноди)
 і від поточної ноди потрібно заразити праве піддерево.
 Це відбувається за довжину правого піддерева
 Потрібно прорахувати суму шляхів від зараженої лівої ноди до
 поточної і від поточної ноди до останньої ноди справа.
 Тому ми рахуємо час так
 time = max(time, left.distToInf + right.length)
 Робимо так, тому що можливе таке дерево, де заражена нода має дерево
 довжиною 1000 до прикладу, а дерево над нею лише довижну 15.
 */
