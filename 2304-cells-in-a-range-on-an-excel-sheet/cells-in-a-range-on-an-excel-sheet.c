#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **cellsInRange(char *s, int* returnSize) {
    int startRow = s[1] - '0';
    int endRow = s[4] - '0';
    char startCol = s[0];
    char endCol = s[3];
    
    *returnSize = (endRow - startRow + 1) * (endCol - startCol + 1);
    char **ans = (char **)malloc(*returnSize * sizeof(char *));
    
    int idx = 0;
    for (char ch = startCol; ch <= endCol; ch++) {
        for (int i = startRow; i <= endRow; i++) {
            ans[idx] = (char *)malloc(3 * sizeof(char));  // 2 characters and null terminator
            snprintf(ans[idx], 3, "%c%d", ch, i);  // Create the cell string
            idx++;
        }
    }
    
    return ans;
}

// int main() {
//     char s[6];
//     int returnSize;

//     // 범위를 입력 받습니다.
//     printf("셀의 범위를 입력하세요 (예: A1:B2): ");
//     scanf("%s", s);

//     // 결과를 계산하고 출력합니다.
//     char **result = cellsInRange(s, &returnSize);
//     printf("해당 범위의 셀 목록:\n");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%s ", result[i]);
//         free(result[i]);  // 각 문자열 메모리 해제
//     }
//     free(result);  // 전체 배열 메모리 해제

//     return 0;
// }
