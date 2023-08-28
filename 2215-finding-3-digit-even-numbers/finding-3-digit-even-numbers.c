#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
    // 각 숫자의 빈도를 저장하기 위한 배열 초기화
    int count[10] = {0};
    // 주어진 숫자들의 빈도를 계산
    for (int i = 0; i < digitsSize; i++) count[digits[i]]++;

    // 결과를 저장할 배열 동적 할당
    int* result = (int*)malloc(sizeof(int) * 450);  // 3자리 짝수의 최대 개수는 450개입니다 (100~998)
    int index = 0;

    // 100부터 998까지 모든 짝수에 대해
    for (int num = 100; num < 999; num += 2) {
        // 현재 숫자의 빈도를 계산
        int currCount[10] = {0};
        int temp = num;

        while (temp) {
            currCount[temp % 10]++;
            temp /= 10;
        }

        // 현재 숫자를 만들 수 있는지 여부를 확인
        bool flag = true;
        for (int i = 0; i < 10; i++) {
            if (currCount[i] > count[i]) {
                flag = false;
                break;
            }
        }

        // 만들 수 있다면 결과 배열에 추가
        if (flag) {
            result[index++] = num;
        }
    }

    // 결과의 크기를 returnSize에 저장
    *returnSize = index;
    return result;
}

// int main() {
//     int n;
//     printf("숫자의 개수를 입력하세요: ");
//     scanf("%d", &n);

//     int digits[n];
//     printf("%d개의 숫자를 입력하세요 (0-9 사이의 숫자): ", n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &digits[i]);
//     }

//     int returnSize;
//     // findEvenNumbers 함수 호출
//     int* evenNumbers = findEvenNumbers(digits, n, &returnSize);

//     printf("3자리 짝수의 가능한 조합: ");
//     for (int i = 0; i < returnSize; i++) {
//         printf("%d ", evenNumbers[i]);
//     }
//     printf("\n");

//     free(evenNumbers);
//     return 0;
// }
