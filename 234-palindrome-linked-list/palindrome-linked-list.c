/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    if(head==NULL || head->next==NULL)return head;

    while (cur!=NULL){
        struct ListNode* nxt = cur->next;
        cur->next = prev;
        prev=cur;
        cur=nxt;
    }
    return prev;
}
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;  // An empty list or single-node list is considered a palindrome
    }

    // Find the middle of the linked list using the slow and fast pointer approach
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    struct ListNode* secondHalfReversed = reverseList(slow);

    // Compare the first half with the reversed second half
    while (secondHalfReversed != NULL) {
        if (head->val != secondHalfReversed->val) {
            // Clean up the reversed second half before returning
            reverseList(slow);
            return false;
        }

        head = head->next;
        secondHalfReversed = secondHalfReversed->next;
    }

    // Clean up the reversed second half before returning
    reverseList(slow);

    return true;
}