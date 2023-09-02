#include <iostream>

// /**
//  * Definition for a binary tree node.
//  */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    bool checkTree(TreeNode* root) {
        if (!root) return false; // 루트 노드가 nullptr인 경우 false 반환
        if (!root->left || !root->right) return false; // 루트 노드의 왼쪽 또는 오른쪽 자식 노드가 nullptr인 경우 false 반환

        // 루트 노드의 값이 왼쪽 및 오른쪽 자식 노드의 값의 합과 같은지 확인
        return root->left->val + root->right->val == root->val;
    }
};

// int main() {
//     // 테스트 코드 작성 (예시)
//     TreeNode* root = new TreeNode(10);
//     root->left = new TreeNode(5);
//     root->right = new TreeNode(5);

//     Solution solution;
//     bool result = solution.checkTree(root);
//     if (result) {
//         printf("루트 노드의 값이 왼쪽 및 오른쪽 자식 노드의 값의 합과 같습니다.\n");
//     } else {
//         printf("루트 노드의 값이 왼쪽 및 오른쪽 자식 노드의 값의 합과 다릅니다.\n");
//     }

//     // 메모리 해제
//     delete root->left;
//     delete root->right;
//     delete root;

//     return 0;
// }
