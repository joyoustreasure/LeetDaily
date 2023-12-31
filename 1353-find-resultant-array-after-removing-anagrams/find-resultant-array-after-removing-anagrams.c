#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH      (100+4)

int compareChar(const void* c1, const void* c2)
{
    // ascending order
    return (*(char*)c1 - *(char*)c2);
}

bool isAnagrams(char* pSrc, char* pDst)
{
    int retVal = false;

    char sortSrc[MAX_LENGTH];
    memset(sortSrc, 0, sizeof(sortSrc));
    snprintf(sortSrc, sizeof(sortSrc), "%s", pSrc);
    qsort(sortSrc, strlen(sortSrc), sizeof(char), compareChar);

    char sortDst[MAX_LENGTH];
    memset(sortDst, 0, sizeof(sortDst));
    snprintf(sortDst, sizeof(sortDst), "%s", pDst);
    qsort(sortDst, strlen(sortDst), sizeof(char), compareChar);

    if (strcmp(sortSrc, sortDst) == 0)
    {
        retVal = true;
    }

    return retVal;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** removeAnagrams(char ** words, int wordsSize, int* returnSize){
    (*returnSize) = 1;

    int len;
    int i;
    for (i=1; i<wordsSize; ++i)
    {
        if (isAnagrams(words[(*returnSize)-1], words[i]) == true)
        {
            continue;
        }

        if ((*returnSize) != i)
        {
            free(words[(*returnSize)]);
            words[(*returnSize)] = NULL;

            len = strlen(words[i]) + 1;
            words[(*returnSize)] = (char*)malloc(len*sizeof(char));
            if (words[(*returnSize)] == NULL)
            {
                perror("malloc");
                return words;
            }
            memset(words[(*returnSize)], 0, len*sizeof(char));
            snprintf(words[(*returnSize)], len*sizeof(char), "%s", words[i]);
        }

        (*returnSize)++;
    }

    return words;
}

// int main() {
//     int wordsSize = 6;
//     char* sampleWords[] = {"cat", "tac", "dog", "god", "hello", "world"};
//     char** words = (char**)malloc(wordsSize * sizeof(char*));

//     for (int i = 0; i < wordsSize; i++) {
//         words[i] = (char*)malloc((strlen(sampleWords[i]) + 1) * sizeof(char));
//         strcpy(words[i], sampleWords[i]);
//     }

//     int returnSize;
//     char** result = removeAnagrams(words, wordsSize, &returnSize);

//     printf("결과 문자열 목록:\n");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%s\n", result[i]);
//         free(result[i]); // memory cleanup for each string
//     }

//     free(result); // memory cleanup for the array

//     return 0;
// }
