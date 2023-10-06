class Solution:
    def integerBreak(self, n: int) -> int:
        if n<=2:
            return 1
        dp = [0,0,1,2]
        for i in range(4,n+1):
            dp.append(max(max(3*dp[i-3],3*(i-3)),max(2*dp[i-2],2*(i-2))))
        return dp[n]