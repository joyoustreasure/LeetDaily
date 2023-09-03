#include <iostream>
using namespace std;

// // 트리 노드 구조체 정의
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    // 트리를 평가하는 함수
    bool evaluateTree(TreeNode* root) {
        // 기본 경우: 리프 노드
        if (root->val < 2) return root->val;
        // OR 노드
        else if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        // AND 노드
        return evaluateTree(root->left) && evaluateTree(root->right);
    }
};

// int main() {
//     // 테스트를 위한 트리 구성
//     TreeNode* root = new TreeNode(3);  // AND
//     root->left = new TreeNode(1);      // True
//     root->right = new TreeNode(2);     // OR
//     root->right->left = new TreeNode(0); // False
//     root->right->right = new TreeNode(1); // True

//     Solution solution;

//     if (solution.evaluateTree(root)) {
//         cout << "트리의 평가 결과: True" << endl;
//     } else {
//         cout << "트리의 평가 결과: False" << endl;
//     }

//     // 동적 할당된 메모리 해제
//     delete root->right->right;
//     delete root->right->left;
//     delete root->right;
//     delete root->left;
//     delete root;

//     return 0;
// }
