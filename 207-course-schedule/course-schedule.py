class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph=[[]for _ in range(numCourses)]
        visited= [0]*numCourses
        for pair in prerequisites:
            graph[pair[1]].append(pair[0])
        
        def cycle(node: int, visited: List[int]) -> bool:
            visited[node] = 1
            for child in graph[node]:
                if visited[child] == 1 or (visited[child] == 0 and cycle(child, visited)):
                    return True
            visited[node] = 2
            return False

        
        for i in range(numCourses):
            if cycle(i,visited):
                return False
        
        return True


        
        