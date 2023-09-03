#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int upper_bound(int* arr, int size, int value) {
    int low = 0, high = size;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= value) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int* answerQueries(int* nums, int numsSize, int* queries, int queriesSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }
    
    int* ans = (int*)malloc(queriesSize * sizeof(int));
    
    for (int i = 0; i < queriesSize; i++) {
        ans[i] = upper_bound(nums, numsSize, queries[i]);
    }
    
    *returnSize = queriesSize;
    return ans;
}

// int main() {
//     int nums[] = {1, 2, 3, 4, 5};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int queries[] = {5, 10, 15};
//     int queriesSize = sizeof(queries) / sizeof(queries[0]);
//     int returnSize;

//     int* result = answerQueries(nums, numsSize, queries, queriesSize, &returnSize);

//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     // 예상 출력: 2 4 5
//     free(result);
//     return 0;
// }
