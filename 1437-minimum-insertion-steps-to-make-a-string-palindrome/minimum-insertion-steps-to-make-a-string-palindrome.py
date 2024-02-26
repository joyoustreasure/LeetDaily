class Solution:
    def minInsertions(self, s: str) -> Tuple[int, str]:
        n = len(s)
        dp = [[0] * n for _ in range(n)]  # 2D array to store minimum insertions
        for i in range(n - 2, -1, -1):
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1]
                else:
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1

        min_insertions = dp[0][n - 1]

        # Build the minimum insertion string
        result = [''] * (n + min_insertions)
        i, j, k = 0, n - 1, 0

        while i <= j:
            if s[i] == s[j]:
                result[k] = s[i]
                result[-k - 1] = s[i]
                i += 1
                j -= 1
            elif dp[i][j] == dp[i + 1][j] + 1:
                result[k] = s[i]
                result[-k - 1] = s[i]
                i += 1
            else:
                result[k] = s[j]
                result[-k - 1] = s[j]
                j -= 1
            k += 1
        
        return min_insertions