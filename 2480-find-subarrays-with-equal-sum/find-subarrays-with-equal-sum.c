#include <stdio.h>
#include <stdbool.h>

// 선택 정렬 함수
void selectionSort(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = nums[i];
            nums[i] = nums[min_idx];
            nums[min_idx] = temp;
        }
    }
}

bool findSubarrays(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return false;
    }

    for (int i = 1; i < numsSize; i++) {
        nums[i-1] += nums[i];
    }
    numsSize--;  // 마지막 요소 제거

    selectionSort(nums, numsSize);  // 선택 정렬 사용

    for (int i = 1; i < numsSize; i++) {
        if (nums[i-1] == nums[i]) {
            return true;
        }
    }
    return false;
}

// int main() {
//     int nums[] = {1, 2, 3, 5, 3, 2};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);

//     if (findSubarrays(nums, numsSize)) {
//         printf("True: There are repeated sums in consecutive subarrays.\n");
//     } else {
//         printf("False: No repeated sums in consecutive subarrays.\n");
//     }
//     return 0;
// }
