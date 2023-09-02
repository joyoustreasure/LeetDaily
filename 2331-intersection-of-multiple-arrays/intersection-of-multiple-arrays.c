#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int value;
    int count;
} Entry;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int* intersection(int** nums, int numsSize, int* numsColSize, int* returnSize) {
    Entry map[5000]; // 임의로 크기를 정했습니다. 실제로는 문제의 제약에 따라 조절이 필요합니다.
    int mapSize = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsColSize[i]; j++) {
            int found = 0;
            for (int k = 0; k < mapSize; k++) {
                if (map[k].value == nums[i][j]) {
                    map[k].count++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                map[mapSize].value = nums[i][j];
                map[mapSize].count = 1;
                mapSize++;
            }
        }
    }

    int* res = (int*)malloc(5000 * sizeof(int)); // 임의로 크기를 정했습니다.
    *returnSize = 0;

    for (int i = 0; i < mapSize; i++) {
        if (map[i].count == numsSize) {
            res[*returnSize] = map[i].value;
            (*returnSize)++;
        }
    }

    qsort(res, *returnSize, sizeof(int), compare);
    return res;
}


// int main() {
//     int nums1[] = {1, 2, 2, 1};
//     int nums2[] = {2, 2};
//     int nums3[] = {2};
//     int* nums[] = {nums1, nums2, nums3};
//     int numsSize = 3;
//     int numsColSize[] = {4, 2, 1};

//     int returnSize;
//     int* result = intersection(nums, numsSize, numsColSize, &returnSize);

//     printf("Intersection: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     free(result);
//     return 0;
// }
// 이 main 함수는 세 개의 배열 nums1, nums2, nums3를 사용하여 intersection 함수를 호출하고 결과를 출력합니다. 예상 결과는 2입니다, 왜냐하면 모든 배열에 2가 포함되어 있기 때문입니다.





