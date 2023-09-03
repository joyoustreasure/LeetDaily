#include <stdio.h>
#include <stdbool.h>

// 수동으로 배열을 오름차순으로 정렬하는 함수
void sortArray(int* nums, int numsSize) {
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

int minimumOperations(int* nums, int numsSize) {
    // 배열을 오름차순으로 정렬
    sortArray(nums, numsSize);
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > 0) { // 첫 번째 양수를 찾음
            int x = nums[i];
            count++;

            // 해당 양수를 나머지 모든 원소에서 뺌
            for (int j = i; j < numsSize; j++) {
                nums[j] -= x;
            }
        }
    }
    return count;
}

// int main() {
//     int n;
//     printf("정수의 개수를 입력하세요: ");
//     scanf("%d", &n);

//     int nums[n];
//     printf("정수들을 입력하세요: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &nums[i]);
//     }

//     int result = minimumOperations(nums, n);
//     printf("최소 연산 횟수: %d\n", result);

//     return 0;
// }
