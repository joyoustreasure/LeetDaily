int countPalindromicSubsequence(char* s) {
    int res = 0;

    for (char c = 'a'; c <= 'z'; ++c) {
        int i = -1, j = -1;
        for (int k = 0; s[k] != '\0'; ++k) {
            if (s[k] == c) {
                i = k;
                break;
            }
        }

        for (int k = strlen(s) - 1; k >= 0; --k) {
            if (s[k] == c) {
                j = k;
                break;
            }
        }

        if (i > -1) {
            // Count unique characters in the substring s[i+1:j]
            int unique_chars = 0;
            char seen[26] = {0};

            for (int k = i + 1; k < j; ++k) {
                if (!seen[s[k] - 'a']) {
                    ++unique_chars;
                    seen[s[k] - 'a'] = 1;
                }
            }

            res += unique_chars;
        }
    }

    return res;
}