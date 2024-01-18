/*
 https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
*/

#include <iostream>
#include <map>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if( !head || !head->next )
            return head;
        ListNode* currOdd = head;
        ListNode* currEven = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;
        while( currEven )
        {
            if( !currEven->next )
                break;

            currOdd = currOdd->next->next;
            currEven = currEven->next->next;

            odd->next = currOdd;
            even->next = currEven;
            odd = currOdd;
            even = currEven;
        }

        odd->next = evenHead;

        return head;
    }
};


int main()
{
    Solution solution;

    auto *tree1node7 = new ListNode(7);
    auto *tree1node4 = new ListNode(4, tree1node7);
    auto *tree1node6 = new ListNode(6, tree1node4);
    auto *tree1node5 = new ListNode(5, tree1node6);
    auto *tree1node3 = new ListNode(3, tree1node5);
    auto *tree1node1 = new ListNode(1, tree1node3);
    auto *tree1node2 = new ListNode(2, tree1node1);


    auto *tree2node6 = new ListNode(6);
    auto *tree2node5 = new ListNode(5, tree2node6);
    auto *tree2node4 = new ListNode(4, tree2node5);
    auto *tree2node3 = new ListNode(3, tree2node4);
    auto *tree2node2 = new ListNode(2, tree2node3);
    auto *tree2node1 = new ListNode(1, tree2node2);

    //solution.oddEvenList(tree1node2);
    solution.oddEvenList(tree2node1);
}