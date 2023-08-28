#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 내림차순 정렬을 위한 비교 함수
int cmp(const void *a, const void *b){
    return *(int*)a < *(int*)b;
}

int* maxSubsequence(int* nums, int numsSize, int k, int* returnSize){
    int i, j, l = numsSize, dup_count = 0;
    int *sorted = (int*)malloc(l * sizeof(int));
    int *ans = (int*)malloc(k * sizeof(int));
    *returnSize = k;
    
    // 원래 배열을 복사
    memcpy(sorted, nums, l * sizeof(int));
    // 복사한 배열을 내림차순으로 정렬
    qsort(sorted, l, sizeof(int), cmp);
    // k번째로 큰 값을 찾음
    int kthMax = sorted[k - 1];
    
    // k번째로 큰 값과 같은 다른 원소들의 개수를 확인
    for(i = k - 1; i >= 0; i--){
        if(sorted[i] == kthMax)
            dup_count++;
        else
            break;
    }
    
    // 원래 배열을 순회하면서 결과 배열에 원소를 추가
    for(i = 0, j = 0; i < l; i++){
        if(nums[i] > kthMax)
            ans[j++] = nums[i];
        else if(nums[i] == kthMax){
            if(dup_count > 0){
                ans[j++] = nums[i];
                dup_count--;
            }
        }
    }
    
    free(sorted);
    return ans;
}

// int main() {
//     int n, k;
//     printf("배열의 크기를 입력하세요: ");
//     scanf("%d", &n);

//     int* nums = (int*)malloc(sizeof(int) * n);
//     printf("%d개의 숫자를 입력하세요: ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &nums[i]);
//     }

//     printf("부분 수열의 길이 k를 입력하세요: ");
//     scanf("%d", &k);

//     int returnSize;
//     int* result = maxSubsequence(nums, n, k, &returnSize);

//     printf("합이 최대가 되는 길이 %d인 부분 수열: ", k);
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }
//     printf("\n");

//     free(nums);
//     free(result);
//     return 0;
// }
