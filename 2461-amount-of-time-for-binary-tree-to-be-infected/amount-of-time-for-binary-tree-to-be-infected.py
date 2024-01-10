# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def make_graph(node):
            if node is None:
                return
            if node.left:
                graph[node.val].append(node.left.val)
                graph[node.left.val].append(node.val)
            if node. right:
                graph[node.val].append(node.right.val)
                graph[node.right.val].append(node.val)
            make_graph(node.left)
            make_graph(node.right)
        
        graph = defaultdict(list)
        make_graph(root)
        visited=set()
        queue = deque([start])
        time = -1
        while queue:
            time+=1
            for _ in range(len(queue)):
                curr_node = queue.popleft()
                visited.add(curr_node)
                for neighbor in graph[curr_node]:
                    if neighbor not in visited:
                        queue.append(neighbor)
        return time