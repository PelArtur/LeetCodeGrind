/*
 https://leetcode.com/problems/reverse-linked-list/?envType=study-plan-v2&envId=leetcode-75
 */

#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
private:
    ListNode * start;
public:
    ListNode* reverseNodes(ListNode* head){
        if(head->next == nullptr){
            ListNode * newHead = new ListNode(head->val);
            start = newHead;

            return newHead;
        }

        ListNode * node = head;
        ListNode * temp = reverseNodes(head->next);
        temp->next = node;
        node->next = nullptr;

        return node;

    }
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return head;
        }
        reverseNodes(head);

        return start;
    }
};
/*
 Main idea:

 Збеігаємо поточний елемент, який стане наступним.
 Отримуємо через рекурсію наступний елемент.
 Base case: наступний елемент nullptr
 У такому випадку ми зараз на останньому елементі
 в списку, тому зберігаємо цей елемент як початок.
 повертаємо цей елемент. Далі робимо наступним
 елементом для повернутого елементу елемент, що
 був попереднім. У кінці повертаємо збережений початок.
 */