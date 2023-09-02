#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 숫자를 문자열로 변환하는 함수
void intToStr(int num, char* str) {
    sprintf(str, "%d", num);
}

// 직접 구현한 버블 정렬 함수
void bubbleSort(char* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int largestInteger(int num) {
    char str[12]; // int의 최대 크기를 고려한 버퍼 크기
    intToStr(num, str);

    char even[12] = {0};
    char odd[12] = {0};
    int evenIdx = 0;
    int oddIdx = 0;

    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] - '0') % 2 == 0) {
            even[evenIdx++] = str[i];
        } else {
            odd[oddIdx++] = str[i];
        }
    }

    // 짝수와 홀수 문자열을 내림차순으로 정렬
    bubbleSort(even, evenIdx);
    bubbleSort(odd, oddIdx);

    char ans[12] = {0};
    int ansIdx = 0;
    evenIdx = 0;
    oddIdx = 0;

    // 원래 순서에 따라 홀수와 짝수를 합침
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] - '0') % 2 == 0) {
            ans[ansIdx++] = even[evenIdx++];
        } else {
            ans[ansIdx++] = odd[oddIdx++];
        }
    }

    return atoi(ans); // 합쳐진 문자열을 숫자로 변환하여 반환
}

// int main() {
//     int num;

//     printf("숫자를 입력하세요: ");
//     scanf("%d", &num);

//     printf("변환된 숫자: %d\n", largestInteger(num));

//     return 0;
// }
