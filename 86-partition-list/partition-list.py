# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        part1=ListNode(-1000)
        part2=ListNode(-1000)
        cur = head
        cur_1,cur_2=part1,part2
        while cur:
            if cur.val<x:
                cur_1.next=ListNode(cur.val)
                cur_1=cur_1.next
            else:
                cur_2.next=ListNode(cur.val)
                cur_2=cur_2.next
            cur=cur.next
        cur_1.next=part2.next
        return part1.next