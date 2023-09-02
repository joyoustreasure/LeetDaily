#include <stdio.h>
#include <stdlib.h>
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes){
    // 범위가 -1000에서 1000까지이므로 총 2001개의 요소가 필요합니다.
    int* hash = (int*)calloc(2001, sizeof(int));
    int** ans = (int**)malloc(sizeof(int*) * 2);
    ans[0] = (int*)calloc(nums1Size, sizeof(int));
    ans[1] = (int*)calloc(nums2Size, sizeof(int));
    
    // nums2의 모든 요소에 대해 hash 값을 1로 설정합니다.
    for(int i = 0; i < nums2Size; i++)
        hash[nums2[i]+1000] = 1;
    
    for(int i = 0; i < nums1Size; i++)
    {
        if(hash[nums1[i]+1000]>0) // nums1과 nums2 모두에 존재하는 요소인 경우
            hash[nums1[i]+1000]++;
        else // 오직 nums1에만 존재하는 요소인 경우
            hash[nums1[i]+1000] = -1;
    }
    int* col = (int*)calloc(2, sizeof(int));
    for(int i = -1000; i <= 1000; i++)
    {
        if(hash[i+1000] == -1) // nums1에만 존재하는 요소
            ans[0][col[0]++] = i;
        else if(hash[i+1000] == 1) // nums2에만 존재하는 요소
            ans[1][col[1]++] = i;
    }
    
    // 반환될 크기와 각 하위 배열의 크기를 설정합니다.
    *returnSize = 2;
    *returnColumnSizes = col;
    return ans;
}


// int main() {
//     int nums1[] = {1, 2, 3, 4};
//     int nums1Size = sizeof(nums1) / sizeof(nums1[0]);
//     int nums2[] = {3, 4, 5, 6};
//     int nums2Size = sizeof(nums2) / sizeof(nums2[0]);

//     int returnSize;
//     int* returnColumnSizes;
//     int** result = findDifference(nums1, nums1Size, nums2, nums2Size, &returnSize, &returnColumnSizes);

//     printf("nums1에서만 있는 요소: ");
//     for (int i = 0; i < returnColumnSizes[0]; i++) {
//         printf("%d ", result[0][i]);
//     }
//     printf("\n");

//     printf("nums2에서만 있는 요소: ");
//     for (int i = 0; i < returnColumnSizes[1]; i++) {
//         printf("%d ", result[1][i]);
//     }
//     printf("\n");

//     // 할당된 메모리 해제
//     free(returnColumnSizes);
//     free(result[0]);
//     free(result[1]);
//     free(result);

//     return 0;
// }
