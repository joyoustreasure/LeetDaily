// #include <stdbool.h>
// #include <stdio.h>

// // TreeNode 구조체 정의
// struct TreeNode {
//     int val;
//     struct TreeNode* left;
//     struct TreeNode* right;
// };

bool checkTree(struct TreeNode* root) {
    // 루트 노드나 자식 노드 중 nullptr인 경우를 검사
    if (!root || !root->left || !root->right) return false;

    // 루트 노드의 값이 왼쪽 및 오른쪽 자식 노드의 값의 합과 같은지 확인
    return root->left->val + root->right->val == root->val;
}

// int main() {
//     // 테스트 코드 작성 (예시)
//     struct TreeNode node1 = {5, NULL, NULL};
//     struct TreeNode node2 = {5, NULL, NULL};
//     struct TreeNode root = {10, &node1, &node2};

//     bool result = checkTree(&root);
//     if (result) {
//         printf("루트 노드의 값이 왼쪽 및 오른쪽 자식 노드의 값의 합과 같습니다.\n");
//     } else {
//         printf("루트 노드의 값이 왼쪽 및 오른쪽 자식 노드의 값의 합과 다릅니다.\n");
//     }

//     return 0;
// }
