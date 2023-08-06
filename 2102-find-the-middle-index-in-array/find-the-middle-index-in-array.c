int findMiddleIndex(int* nums, int numsSize){
 int l_sum = 0, r_sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        r_sum += nums[i];
    }

    for (int i = 0; i < numsSize; ++i) {
        if (l_sum == r_sum - nums[i]) {
            return i;
        }

        l_sum += nums[i];
        r_sum -= nums[i];
    }

    return -1;
}