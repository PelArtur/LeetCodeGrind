/*
 https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr ){
            return head;
        }
        ListNode * start = head->next;
        ListNode * oddHead = head -> next;
        ListNode * evenHead = head;

        while(evenHead -> next && oddHead -> next){
            evenHead -> next = oddHead -> next;
            oddHead -> next = evenHead -> next -> next;

            evenHead = evenHead -> next;
            oddHead = oddHead -> next;
        }

        evenHead -> next = start;
        return head;
    }
};

/*
 Main idea:

 Створюємо пойнтери на початок парних елементів та початок непарних елементів

 Рухаємось по лісту, для парного елемента наступний елемент це наступний елемент
 непарного елемента, а для непарного елемента наступний елемент, це той самий
 наступний елемент що тільки що змінився для парного, тільки наступний елемент.

 Це все відбувається допоки наступний елемент нашого парного елементу не почне
 вказувати на nullptr. Це буде відбуватись в разі якщо масив непарної довжини,
 або коли непарний елемент не почне вказувати на Nullptr, це у випадку якщо
 масив парної довжини.

 У кінці нам варто прив'язати початок непарних елементів до кінця непарних елементів
 На початку ми зберегли вказівку на початок непарних елементів, тому прив'язуєм
 ці два значення. Оскільки Input head вказував на початок парних елементів, просто
 повертаємо його.
 */