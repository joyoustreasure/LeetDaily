#include <stdio.h>

int arithmeticTriplets(int* nums, int numsSize, int diff) {
    int ans = 0;

    // 배열 내의 모든 원소 조합에 대해 산술적인 조합이 있는지 확인
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if ((nums[j] - nums[i]) == diff && (nums[k] - nums[j]) == diff) {
                    ans++;
                }
            }
        }
    }
    return ans;
}

// int main() {
//     int nums[] = {1, 3, 5, 7, 9, 11};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int diff = 2;

//     int result = arithmeticTriplets(nums, numsSize, diff);
//     printf("산술적인 삼중 숫자 조합의 수: %d\n", result);

//     return 0;
// }
