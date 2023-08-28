/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comparator(const void *a, const void *b){
    int *x = (int *)a;
    int *y = (int *)b;
    if(*x < *y) return -1;
    return 1;
}
int* targetIndices(int* nums, int numsSize, int target, int* returnSize){
    qsort(nums, numsSize, sizeof(int), comparator);
    int *arr = (int *)malloc(sizeof(int)*numsSize);
    int index = 0;
    for (int i = 0; i < numsSize; i++)
    {
        /* code */
        if(nums[i] == target) arr[index++] = i;
    }
    *returnSize = index;
    return arr;
}