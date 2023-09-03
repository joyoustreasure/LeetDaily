#include <stdio.h>
#include <stdlib.h>

int* numberOfPairs(int* nums, int numsSize, int* returnSize) {
    // 배열 nums에 있는 가능한 최대 값이 1000이라고 가정합니다.
    int maxVal = 1000;
    // 숫자의 빈도를 저장하기 위한 배열을 초기화합니다.
    int* freq = (int*)calloc(maxVal + 1, sizeof(int));

    // 각 숫자의 빈도를 계산합니다.
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    int count = 0, count1 = 0;
    // 페어를 만들 수 있는 개수와 만들 수 없는 개수를 계산합니다.
    for (int i = 0; i <= maxVal; i++) {
        count += (freq[i] / 2);
        count1 += (freq[i] % 2);
    }

    free(freq);

    // 결과를 저장할 배열을 할당하고 값을 저장합니다.
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = count;
    result[1] = count1;

    *returnSize = 2;
    return result;
}

// int main() {
//     int nums[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int returnSize;

//     int* result = numberOfPairs(nums, numsSize, &returnSize);
//     printf("만들 수 있는 페어의 개수: %d\n", result[0]);
//     printf("페어를 만들 수 없는 남은 숫자의 개수: %d\n", result[1]);

//     free(result);
//     return 0;
// }
