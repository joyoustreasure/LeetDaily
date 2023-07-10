class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        if rows == 0:
            return 0
        
        dist= [[rows*cols for _ in range(cols)] for _ in range(rows)]

        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                if mat[i][j]==0:
                    dist[i][j]=0
                
                else:
                    right = dist[i][j+1] if (j+1)< cols else rows*cols
                    down = dist[i+1][j] if (i+1)<rows else rows*cols
                    dist[i][j] = 1 + min(right, down)

        for i in range(rows):
            for j in range(cols):
                if mat[i][j]==0:
                    dist[i][j]=0
                else:
                    left = dist[i][j-1] if (j-1)>=0 else rows*cols
                    top = dist[i-1][j] if (i-1)>=0 else rows*cols
                    dist[i][j] = min(dist[i][j], 1 + min(left, top))





        return dist
