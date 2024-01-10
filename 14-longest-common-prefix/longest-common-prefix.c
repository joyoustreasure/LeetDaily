#define MAX_LENGTH 1000 

char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0) return "";

    static char commonPrefix[MAX_LENGTH];
    strcpy(commonPrefix, strs[0]); // 첫 번째 문자열로 초기화

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (commonPrefix[j] && strs[i][j] && commonPrefix[j] == strs[i][j]) {
            j++;
        }
        commonPrefix[j] = '\0';

        if (commonPrefix[0] == '\0') break;
    }

    return commonPrefix;
}