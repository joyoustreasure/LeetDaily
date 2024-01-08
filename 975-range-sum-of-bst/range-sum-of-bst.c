/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int rangeSumBST(struct TreeNode* root, int low, int high) {
    if (root == NULL) {
        return 0;
    } else if (root->val < low) {
        return rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
        return rangeSumBST(root->left, low, high);
    }
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}