#include <stdio.h>
#include <stdlib.h>

int** mergeSimilarItems(int** items1, int items1Size, int* items1ColSize, int** items2, int items2Size, int* items2ColSize, int* returnSize, int** returnColumnSizes) {
    // 최대 ID 값을 찾습니다.
    int maxID = 0;
    for (int i = 0; i < items1Size; i++) {
        if (items1[i][0] > maxID) {
            maxID = items1[i][0];
        }
    }
    for (int i = 0; i < items2Size; i++) {
        if (items2[i][0] > maxID) {
            maxID = items2[i][0];
        }
    }

    // 최대 ID 값을 기반으로 map 배열의 크기를 할당합니다.
    int* map = (int*)calloc(maxID + 1, sizeof(int));

    for (int i = 0; i < items1Size; i++) {
        map[items1[i][0]] += items1[i][1];
    }

    for (int i = 0; i < items2Size; i++) {
        map[items2[i][0]] += items2[i][1];
    }

    *returnSize = 0;
    for (int i = 0; i <= maxID; i++) {
        if (map[i] != 0) {
            (*returnSize)++;
        }
    }

    int** result = (int**) malloc(*returnSize * sizeof(int*));
    *returnColumnSizes = (int*) malloc(*returnSize * sizeof(int));

    int index = 0;
    for (int i = 0; i <= maxID; i++) {
        if (map[i] != 0) {
            result[index] = (int*) malloc(2 * sizeof(int));
            (*returnColumnSizes)[index] = 2;
            result[index][0] = i;
            result[index][1] = map[i];
            index++;
        }
    }

    free(map);
    return result;
}

// int main() {
//     int items1Size = 1;
//     int** items1 = (int**)malloc(items1Size * sizeof(int*));
//     items1[0] = (int*)malloc(2 * sizeof(int));
//     items1[0][0] = 1; 
//     items1[0][1] = 1;

//     int items2Size = 1;
//     int** items2 = (int**)malloc(items2Size * sizeof(int*));
//     items2[0] = (int*)malloc(2 * sizeof(int));
//     items2[0][0] = 1000; 
//     items2[0][1] = 1000;

//     int returnSize;
//     int* returnColumnSizes;
//     int** merged = mergeSimilarItems(items1, items1Size, NULL, items2, items2Size, NULL, &returnSize, &returnColumnSizes);

//     for (int i = 0; i < returnSize; i++) {
//         printf("ID: %d, Value: %d\n", merged[i][0], merged[i][1]);
//         free(merged[i]);
//     }
//     free(merged);
//     free(returnColumnSizes);

//     for (int i = 0; i < items1Size; i++) {
//         free(items1[i]);
//     }
//     free(items1);
//     for (int i = 0; i < items2Size; i++) {
//         free(items2[i]);
//     }
//     free(items2);

//     return 0;
// }
