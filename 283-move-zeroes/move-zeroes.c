void moveZeroes(int* nums, int numsSize) {
    int cnt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[cnt] = nums[i];
            cnt += 1;
        }
    }


    for (int j = cnt; j < numsSize; j++) {
        nums[j] = 0;
    }
}
