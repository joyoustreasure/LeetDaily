#include <stdio.h>

int maximumDifference(int* nums, int numsSize) {
    int cur = -1;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[j] - nums[i] > cur && nums[j] != nums[i]) {
                cur = nums[j] - nums[i];
            }
        }
    }
    return cur;
}
