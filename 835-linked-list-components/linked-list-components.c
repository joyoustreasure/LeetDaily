/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int c[1000000]={0};
    for (int i=0;i<numsSize;i++) c[nums[i]]+=1;

    struct ListNode* cur = head;
    int cnt=0;
    while (cur!=NULL){
        if (c[cur->val]==1){
            while(cur!=NULL&&c[cur->val]==1){cur=cur->next;}
            cnt++;
        }
        else cur = cur->next;
    }
    return cnt;
}