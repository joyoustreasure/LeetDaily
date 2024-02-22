class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        y_len, x_len = len(matrix), len(matrix[0])

        def inRange(x: int, y: int) -> bool:
            return 0 <= x < x_len and 0 <= y < y_len

        graph = dict()
        dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]

        for x in range(x_len):
            for y in range(y_len):
                graph[(x, y)] = []
                for d in range(4):
                    new_x, new_y = x + dx[d], y + dy[d]
                    if inRange(new_x, new_y) and matrix[new_y][new_x] > matrix[y][x]:
                        graph[(x, y)].append((new_x, new_y))

        memo = dict()

        def dfs(x: int, y: int):
            if (x, y) in memo:
                return memo[(x, y)]
            result = 1 

            for nx, ny in graph[(x, y)]:
                result = max(result, 1 + dfs(nx, ny))

            memo[(x, y)] = result
            return result

        max_length = 0

        for x in range(x_len):
            for y in range(y_len):
                max_length = max(max_length, dfs(x, y))

        return max_length