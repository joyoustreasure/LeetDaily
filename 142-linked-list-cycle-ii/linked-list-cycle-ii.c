/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
*/

struct ListNode *detectCycle(struct ListNode *head) {
    
    // Initial Condition for for no node or no cycle
    if(head == NULL || head->next == NULL)return NULL;
    
    struct ListNode* slowptr = head;//Slow Pointer
    struct ListNode* fastptr = head;//Fast Pointer
    struct ListNode* entryptr = head; // entry location
    
    //Search of the loop cycle using fast pointer
    while(fastptr->next && fastptr->next->next){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        
        //Condition if cycle exist, if cycle exist then check the entry point of the cycle further
        if(slowptr == fastptr){
            
            //loop to check the entrypoint of the cycle, 
            //once found return the pointer to the entry point 
            while(slowptr != entryptr){
                slowptr = slowptr->next;
                entryptr = entryptr->next;
            }
            return entryptr;
        }
    }
    return NULL;
}