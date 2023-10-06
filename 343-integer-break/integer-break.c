int max(int a, int b) {
    return a > b ? a : b;
}

int integerBreak(int n) {
    if (n <= 2) {
        return 1;
    }
    int* dp = (int*)malloc(sizeof(int) * (n + 1));
    if (dp == NULL) {
        return -1;
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i < n + 1; i++) {
        dp[i] = max(max(3 * dp[i - 3], 3 * (i - 3)), max(2 * dp[i - 2], 2 * (i - 2)));
    }
    int result = dp[n];
    free(dp);
    return result;
}