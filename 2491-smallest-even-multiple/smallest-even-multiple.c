#include <stdio.h>

// 주어진 정수 n에 대해 가장 작은 짝수 배를 반환하는 함수
int smallestEvenMultiple(int n) {
    if(n % 2 == 0)  // n이 짝수인 경우
        return n;
    else  // n이 홀수인 경우
        return n * 2;
}

// int main() {
//     int num;
//     printf("정수를 입력하세요: ");
//     scanf("%d", &num);
//     printf("%d의 가장 작은 짝수 배는 %d입니다.\n", num, smallestEvenMultiple(num));
//     return 0;
// }
