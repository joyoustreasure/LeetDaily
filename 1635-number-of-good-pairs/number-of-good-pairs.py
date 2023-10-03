class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        visited={}
        for num in nums:
            if num not in visited:
                visited[num]=1
            else:
                visited[num]+=1
        
        good=0
        for num in visited.keys():
            if visited[num]>1:
                good+=int(visited[num]*(visited[num]-1)/2)
        return good