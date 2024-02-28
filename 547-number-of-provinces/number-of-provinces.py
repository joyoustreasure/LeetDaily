class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        def dfs(start:int, visited:set):
            visited.add(start)
            for i in range(len(isConnected[start])):
                if i not in visited and isConnected[start][i] == 1 :
                    dfs(i, visited)
        visited=set()
        cnt=0
        for i in range(len(isConnected)):
            if i not in visited:
                cnt+=1
                dfs(i,visited)
        return cnt

