"""
https://leetcode.com/problems/odd-even-linked-list/description/?envType=study-plan-v2&envId=leetcode-75
"""
from typing import Optional, List


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        curr_odd = head
        curr_even = head.next
        
        odd = curr_odd
        even = curr_even
        
        even_head = even
        
        while curr_even and curr_even.next:
            curr_even = curr_even.next.next
            curr_odd = curr_odd.next.next
            
            odd.next = curr_odd
            even.next = curr_even
            
            odd = odd.next
            even = even.next
            
        odd.next = even_head
        
        return head

if __name__ == "__main__":
    solution = Solution()
    
    tree1node7 = ListNode(7)
    tree1node4 = ListNode(4, tree1node7)
    tree1node6 = ListNode(6, tree1node4)
    tree1node5 = ListNode(5, tree1node6)
    tree1node3 = ListNode(3, tree1node5)
    tree1node1 = ListNode(1, tree1node3)
    tree1node2 = ListNode(2, tree1node1)
    
    tree2node6 = ListNode(6)
    tree2node5 = ListNode(5, tree2node6)
    tree2node4 = ListNode(4, tree2node5)
    tree2node3 = ListNode(3, tree2node4)
    tree2node2 = ListNode(2, tree2node3)
    tree2node1 = ListNode(1, tree2node2)
    
    solution.oddEvenList(tree1node2)
    solution.oddEvenList(tree2node1)
