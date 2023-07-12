class Solution:
    def divide(self, head):
        slow, fast = head, head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        second_half = slow.next
        
        slow.next = None

        return second_half
    
    def merge(self, l, r):
        tmp = ans = ListNode()
        while l and r:
            if l.val <= r.val:
                tmp.next = l
                l = l.next
            else:
                tmp.next = r
                r = r.next
            tmp = tmp.next
        if l:
            tmp.next = l
        elif r:
            tmp.next = r
        return ans.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        left = head
        right = self.divide(head)
        left = self.sortList(left)
        right = self.sortList(right)
        
        return self.merge(left, right)
