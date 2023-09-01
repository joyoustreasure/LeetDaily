#include <stdio.h>

// 주어진 조건을 만족하는 숫자 쌍의 수를 계산하는 함수
int countPairs(int* nums, int numsSize, int k) {
    int count = 0;

    // 모든 숫자 쌍에 대해
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // 조건을 검사
            if (nums[i] == nums[j] && i * j % k == 0) {
                count++;
            }
        }
    }

    return count;  // 결과 반환
}

// int main() {
//     int nums[] = {1, 2, 2, 3, 4, 4};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int k = 2;

//     // 결과를 계산하고 출력
//     int result = countPairs(nums, numsSize, k);
//     printf("조건을 만족하는 숫자 쌍의 수: %d\n", result);

//     return 0;
// }
