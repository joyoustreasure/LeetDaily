/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;

    // 이 부분에서 left-2로 설정하면서 left-1 번째 노드까지 이동하려고 했으나,
    // left가 1일 때는 cur가 head를 가리켜야 하므로 left-1이 아닌 left-2로 설정하면 안 됩니다.
    for (int i = 0; i < left - 1; i++) {
        prev = cur;
        cur = cur->next;
    }

    struct ListNode* left_ptr = cur;  // left 번째 노드를 가리킴
    struct ListNode* tail = prev;     // left-1 번째 노드를 가리킴

    // 이 부분에서 right-left+1로 설정하여 뒤집어야 하는 노드들의 개수를 구합니다.
    for (int j = 0; j < right - left + 1; j++) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // 뒤집힌 부분의 첫 번째 노드와 마지막 노드를 연결합니다.
    if (tail != NULL) {
        tail->next = prev;
    } else {
        head = prev;
    }

    left_ptr->next = cur;

    return head;
}
