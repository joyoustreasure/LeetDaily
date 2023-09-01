#include <stdio.h>

// 주어진 숫자 n의 각 자릿수의 합을 반환하는 함수
int sod(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;  // 현재 자릿수를 합에 추가
        n /= 10;  // 다음 자릿수로 이동
    }
    return sum;
}

// 2부터 num까지의 숫자 중에서 각 자릿수의 합이 짝수인 숫자의 개수를 반환하는 함수
int countEven(int num) {
    int c = 0;
    for (int i = 2; i <= num; i++) {
        if (sod(i) % 2 == 0)  // 각 자릿수의 합이 짝수인 경우
            c += 1;
    }
    return c;
 }

// int main() {
//     int num;

//     // 숫자를 입력 받습니다.
//     printf("숫자를 입력하세요: ");
//     scanf("%d", &num);

//     // 결과를 계산하고 출력합니다.
//     int result = countEven(num);
//     printf("2부터 %d까지 각 자릿수의 합이 짝수인 숫자의 개수: %d\n", num, result);

//     return 0;
// }
