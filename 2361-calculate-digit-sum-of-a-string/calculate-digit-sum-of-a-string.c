#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * digitSum(char * s, int k) {
    int length = strlen(s);
    char *ans = (char *)malloc(length + 1); // +1 for the null-terminator

    while (1) {
        if (length <= k) {
            return s;
        }

        int sum = 0;
        int ansIndex = 0; // For populating the answer

        for (int i = 0; i < length; i++) {
            if (i != 0 && i % k == 0) {
                ansIndex += sprintf(ans + ansIndex, "%d", sum); // Add sum to ans
                sum = 0;
            }
            sum += s[i] - '0';
        }
        
        sprintf(ans + ansIndex, "%d", sum); // Add the remaining sum to ans

        strcpy(s, ans); // Copy answer to s for the next iteration
        length = strlen(s); // Update length
        memset(ans, 0, length + 1); // Reset ans
    }

    free(ans);
    return s;
}

// int main() {
//     char s[] = "123456789";
//     int k = 3;
//     printf("%s\n", digitSum(s, k)); // Expected output: "152491223"
//     return 0;
// }
