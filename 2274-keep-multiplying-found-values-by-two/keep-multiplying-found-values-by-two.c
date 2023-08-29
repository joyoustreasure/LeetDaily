#include <stdio.h>

int findFinalValue(int* nums, int numsSize, int original) {
    int found = 1; // original이 nums 배열에 있는지 여부를 나타내는 플래그
    while(found) {
        found = 0;
        for(int i = 0; i < numsSize; i++) {
            if(nums[i] == original) {
                original *= 2;
                found = 1;
                break;
            }
        }
    }
    return original;
}

// int main() {
//     int nums[] = {1, 2, 4, 8, 16};
//     int numsSize = sizeof(nums) / sizeof(nums[0]);
//     int original = 2;

//     int result = findFinalValue(nums, numsSize, original);
    
//     printf("The final value is: %d\n", result);

//     return 0;
// }
