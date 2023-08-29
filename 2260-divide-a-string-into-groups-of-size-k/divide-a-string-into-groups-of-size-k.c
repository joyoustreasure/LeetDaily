#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** divideString(char * s, int k, char fill, int* returnSize) {
    int len = strlen(s);
    *returnSize = len / k + (len % k == 0 ? 0 : 1);  // Calculate the number of substrings
    
    char **result = malloc(*returnSize * sizeof(char*));  // Allocate memory for the result

    for (int i = 0, j = 0; i < len; i += k, j++) {
        result[j] = malloc((k + 1) * sizeof(char));  // Allocate memory for each substring

        int count = 0;
        while (i + count < len && count < k) {
            result[j][count] = s[i + count];
            count++;
        }

        // Fill the remaining positions with the fill character
        while (count < k) {
            result[j][count] = fill;
            count++;
        }

        result[j][count] = '\0';  // Null-terminate the string
    }

    return result;
}

// int main() {
//     char s[] = "examplestring";
//     int k = 4;
//     char fill = '*';
//     int returnSize;

//     char **result = divideString(s, k, fill, &returnSize);

//     printf("Result:\n");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%s\n", result[i]);
//         free(result[i]);  // Free each allocated substring
//     }
//     free(result);  // Free the result array

//     return 0;
// }
