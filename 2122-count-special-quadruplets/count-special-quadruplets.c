int countQuadruplets(int* nums, int numsSize) {
    int cnt = 0;

    for (int a = 0; a < numsSize; ++a) {
        for (int b = a + 1; b < numsSize; ++b) {
            for (int c = b + 1; c < numsSize; ++c) {
                for (int d = c + 1; d < numsSize; ++d) {
                    if (nums[a] + nums[b] + nums[c] == nums[d]) {
                        cnt++;
                    }
                }
            }
        }
    }

    return cnt;
}
