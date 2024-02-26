int minInsertions(char* s) {
    int n = strlen(s);

    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; ++i) {
        dp[i] = (int*)malloc(n * sizeof(int));
        memset(dp[i], 0, n * sizeof(int));
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = (dp[i + 1][j] < dp[i][j - 1] ? dp[i + 1][j] : dp[i][j - 1]) + 1;
            }
        }
    }

    int minInsertions = dp[0][n - 1];

    char* result = (char*)malloc((n + minInsertions + 1) * sizeof(char));
    int i = 0, j = n - 1, k = 0;

    while (i <= j) {
        if (s[i] == s[j]) {
            result[k] = s[i];
            result[n + minInsertions - k - 1] = s[i];
            ++i;
            --j;
        } else if (dp[i][j] == dp[i + 1][j] + 1) {
            result[k] = s[i];
            result[n + minInsertions - k - 1] = s[i];
            ++i;
        } else {
            result[k] = s[j];
            result[n + minInsertions - k - 1] = s[j];
            --j;
        }
        ++k;
    }

    result[n + minInsertions] = '\0';

    // Print the result
    printf("Output: (%d, \"%s\")\n", minInsertions, result);

    // Free allocated memory
    for (int i = 0; i < n; ++i) {
        free(dp[i]);
    }
    free(dp);

    // Return the minimum insertions
    return minInsertions;
}