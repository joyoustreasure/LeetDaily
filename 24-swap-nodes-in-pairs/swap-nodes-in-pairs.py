# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head:
            cur=head.next
            if cur:
                cur.next, head.next = head, cur.next
                cur.next.next = self.swapPairs(cur.next.next)
                return cur
        
        return head