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
    ListNode* deleteMiddle(ListNode* head)
    {
        if(!head->next)
            return nullptr;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while(true)
        {
            if(!fast->next || !fast->next->next)
            {
                ListNode *next = slow->next->next;
                slow->next->next = nullptr;
                slow->next = next;
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return head;
    }
};