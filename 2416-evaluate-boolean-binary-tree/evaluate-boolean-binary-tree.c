#include <stdio.h>
#include <stdbool.h>

// // 트리 노드 구조체 정의
// struct TreeNode {
//     int val;
//     struct TreeNode *left;
//     struct TreeNode *right;
// };

bool evaluateTree(struct TreeNode* root) {
    // 기본 경우: 리프 노드
    if (root->val < 2) return root->val;
    // OR 노드
    else if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
    // AND 노드
    return evaluateTree(root->left) && evaluateTree(root->right);
}

// int main() {
//     // 테스트를 위한 트리 구성
//     struct TreeNode a = {3, NULL, NULL}; // AND
//     struct TreeNode b = {1, NULL, NULL}; // True
//     struct TreeNode c = {2, NULL, NULL}; // OR
//     struct TreeNode d = {0, NULL, NULL}; // False
//     struct TreeNode e = {1, NULL, NULL}; // True

//     a.left = &b;
//     a.right = &c;
//     c.left = &d;
//     c.right = &e;

//     if (evaluateTree(&a)) {
//         printf("트리의 평가 결과: True\n");
//     } else {
//         printf("트리의 평가 결과: False\n");
//     }

//     return 0;
// }
