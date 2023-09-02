#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int minMaxGame(int* nums, int numsSize) {
    int n = numsSize;
    
    // 배열의 길이가 1이 될 때까지 반복
    while(n > 1) {
        int k = 0;
        for(int i = 0; i < n / 2; i++) {
            // 홀수 번째 요소는 연속된 두 요소 중 최소값을 선택
            if(k % 2 == 0) nums[k] = min(nums[2 * i], nums[2 * i + 1]);
            // 짝수 번째 요소는 연속된 두 요소 중 최대값을 선택
            else nums[k] = max(nums[2 * i], nums[2 * i + 1]);
            k++;
        }
        // 배열의 길이를 반으로 줄임
        n /= 2;
    }
    // 최종적으로 남아 있는 요소를 반환
    return nums[0];
}

// int main() {
//     int nums[] = {3, 5, 2, 1, 6, 4};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);

//     int result = minMaxGame(nums, numsSize);
//     printf("The final number after playing the min-max game is: %d\n", result);

//     return 0;
// }
