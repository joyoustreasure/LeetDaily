class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        def cycle(prev:int,cur:int):
            if cur in visited:
                return True

            visited.add(cur)
            for nei in graph[cur]:
                if nei!=prev and cycle(cur,nei):
                    return True
        graph = defaultdict(list)
        
        for a,b in edges:
            visited=set()
            graph[a].append(b)
            graph[b].append(a)
            if cycle(a,b):
                return[a,b]
            
        