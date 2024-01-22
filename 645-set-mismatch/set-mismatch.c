/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* cnt = (int*)calloc(numsSize + 1, sizeof(int));
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        cnt[nums[i]]++;
    }
    for (int j = 1; j <= numsSize; j++) {
        if (cnt[j] == 0) {
            result[1] = j;
        } else if (cnt[j] == 2) {
            result[0] = j;
        }
    }

    *returnSize = 2;

    free(cnt); 
    return result;
}