/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    // 두 그룹의 시작을 나타낼 더미 노드를 생성합니다.
    struct ListNode less_dummy;
    struct ListNode greater_dummy;
    
    struct ListNode* less = &less_dummy;
    struct ListNode* greater = &greater_dummy;

    struct ListNode* cur = head;

    while (cur != NULL) {
        if (cur->val < x) {
            // 현재 노드가 x보다 작으면 'less' 그룹에 추가
            less->next = cur;
            less = less->next;
        } else {
            // 현재 노드가 x 이상이면 'greater' 그룹에 추가
            greater->next = cur;
            greater = greater->next;
        }

        // 다음 노드로 이동
        cur = cur->next;
    }

    // 그룹의 끝을 NULL로 설정하여 연결 리스트의 끝을 표시
    greater->next = NULL;

    // 'less' 그룹의 끝을 'greater' 그룹의 시작에 연결하여 두 그룹을 합침
    less->next = greater_dummy.next;

    // 'less' 그룹의 시작인 더미 노드의 다음을 반환
    return less_dummy.next;
}
