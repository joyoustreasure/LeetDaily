#include <stdbool.h>
#include <stdio.h>

#define MAX_NUM 10000  // 예상되는 최대 정수 값. 필요한 경우 이 값을 조정할 수 있습니다.

bool divideArray(int* nums, int numsSize) {
    int freq[MAX_NUM + 1] = {0};  // 0으로 초기화된 빈도 배열

    // 각 숫자의 빈도를 계산
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    // 모든 숫자의 빈도가 짝수인지 확인
    for (int i = 0; i <= MAX_NUM; i++) {
        if (freq[i] % 2 != 0) return false;
    }

    return true;
}

// int main() {
//     int nums[] = {1, 2, 3, 1, 2, 3};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     if (divideArray(nums, numsSize)) {
//         printf("Array can be divided into pairs with the same elements.\n");
//     } else {
//         printf("Array cannot be divided into pairs with the same elements.\n");
//     }
//     return 0;
// }
