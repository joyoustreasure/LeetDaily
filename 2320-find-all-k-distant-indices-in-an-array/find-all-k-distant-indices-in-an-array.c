#include <stdio.h>
#include <stdlib.h>

int* findKDistantIndices(int* nums, int numsSize, int key, int k, int* returnSize){
    // 결과를 저장할 배열 동적 할당
    int* ans = (int*)calloc(numsSize, sizeof(int));
    int ansIdx = 0;  // 결과 배열의 인덱스
    int i = 0;  // nums 배열을 순회할 인덱스

    while(i < numsSize)
    {
        if(nums[i] == key){
            // 이전에 저장된 인덱스를 사용하여 현재 시작 인덱스 결정
            int prevIdx = !ansIdx? -1 : ans[ansIdx - 1];
            int startIdx = ((i-k) > prevIdx) ? (i-k) : (prevIdx + 1);
            
            // i로부터 앞뒤 k 거리의 인덱스들을 ans에 추가
            for(int j = startIdx; j <= (i+k) && j < numsSize; j++)
                ans[ansIdx++] = j;
        }
        i++;
    }
    
    *returnSize = ansIdx;  // 결과 배열의 크기 설정
    return ans;  // 결과 반환
}

// int main() {
//     int n, key, k;

//     // 배열의 크기 입력 받기
//     printf("배열의 크기를 입력하세요: ");
//     scanf("%d", &n);

//     int* nums = (int*)malloc(n * sizeof(int));

//     // 배열의 원소 입력 받기
//     printf("배열의 원소를 입력하세요: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &nums[i]);
//     }

//     // key와 k 입력 받기
//     printf("key 값을 입력하세요: ");
//     scanf("%d", &key);
//     printf("k 값을 입력하세요: ");
//     scanf("%d", &k);

//     // 결과 계산
//     int returnSize;
//     int* result = findKDistantIndices(nums, n, key, k, &returnSize);

//     // 결과 출력
//     printf("k 거리 내의 인덱스: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", result[i]);
//     }

//     free(nums);
//     free(result);

//     return 0;
// }
