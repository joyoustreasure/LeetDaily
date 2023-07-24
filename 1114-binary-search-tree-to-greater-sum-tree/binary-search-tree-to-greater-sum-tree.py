# # Definition for a binary tree node.
# # class TreeNode:
# #     def __init__(self, val=0, left=None, right=None):
# #         self.val = val
# #         self.left = left
# #         self.right = right

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def reverse_inorder_traversal(node, prev_sum):
            if not node:
                return prev_sum

            right_sum = reverse_inorder_traversal(node.right, prev_sum)
            node.val += right_sum

            return reverse_inorder_traversal(node.left, node.val)
        
        reverse_inorder_traversal(root, 0)
        return root

        