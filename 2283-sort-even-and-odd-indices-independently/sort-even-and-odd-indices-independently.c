#include <stdio.h>
#include <stdlib.h>

// 비교 함수: 오름차순 정렬을 위한 함수
int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// 비교 함수: 내림차순 정렬을 위한 함수
int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

// 주어진 배열의 홀수 인덱스에 있는 원소들을 내림차순으로, 
// 짝수 인덱스에 있는 원소들을 오름차순으로 정렬합니다.
// 그리고 홀수와 짝수를 교대로 결과 배열에 추가합니다.
int* sortEvenOdd(int* nums, int numsSize, int* returnSize) {
    int *odd = (int *)malloc(sizeof(int) * numsSize);
    int *even = (int *)malloc(sizeof(int) * numsSize);
    int oddCount = 0, evenCount = 0;

    // 배열의 원소를 홀수와 짝수로 분리
    for (int i = 0; i < numsSize; i++) {
        if (i % 2) even[evenCount++] = nums[i];
        else odd[oddCount++] = nums[i];
    }

    // 홀수와 짝수를 각각 정렬
    qsort(odd, oddCount, sizeof(int), compareAsc);
    qsort(even, evenCount, sizeof(int), compareDesc);

    int *result = (int *)malloc(sizeof(int) * numsSize);
    int i = 0, j = 0, k = 0;

    // 결과 배열에 홀수와 짝수를 교대로 추가
    while (i < oddCount || j < evenCount) {
        if (i < oddCount) result[k++] = odd[i++];
        if (j < evenCount) result[k++] = even[j++];
    }

    // 결과 배열의 크기 설정
    *returnSize = numsSize;

    free(odd);
    free(even);

    return result;
}

// int main() {
//     int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
//     int size = sizeof(nums) / sizeof(nums[0]);
//     int returnSize;
//     int *result;

//     result = sortEvenOdd(nums, size, &returnSize);

//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }

//     free(result);
//     return 0;
// }
