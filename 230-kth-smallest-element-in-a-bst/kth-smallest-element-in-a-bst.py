# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self, cur):
        if not cur:
            return []
        return self.traverse(cur.left) +[cur.val]+ self.traverse(cur.right)

    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        lst= self.traverse(root)
        return lst[k-1]