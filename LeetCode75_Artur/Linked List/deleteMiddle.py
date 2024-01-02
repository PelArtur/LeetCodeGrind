class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def deleteMiddle(self, head: ListNode):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if not head.next:
            return None
        
        slow = head
        fast = head.next
        
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        
        deletedNode = slow.next
        slow.next = deletedNode.next
        deletedNode.next = None
        return head
