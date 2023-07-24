# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: Optional[TreeNode]):
        def traverse( cur):
            if not cur:
                return []
            return  traverse(cur.left) +[cur.val]+ traverse(cur.right)
        self.nodes = traverse(root)
        self.pointer = -1
        self.len = len(self.nodes)

    def next(self) -> int:
        self.pointer+=1
        return self.nodes[self.pointer]

    def hasNext(self) -> bool:
        return self.pointer<self.len-1


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()