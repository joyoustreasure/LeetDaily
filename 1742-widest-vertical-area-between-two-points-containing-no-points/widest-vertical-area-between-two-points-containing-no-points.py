class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        sort = sorted(points, key=lambda x: x[0])
        
        M=0
        for i in range(len(points)-1):
            val=sort[i+1][0]-sort[i][0]
            if val>M:
                M=val
        return M