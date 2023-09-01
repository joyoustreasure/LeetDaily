#include <stdio.h>

// 두 수에 대해 연산을 수행하고 연산의 횟수를 반환하는 함수
int countOperations(int num1, int num2) {
    int operation = 0;  // 연산 횟수를 저장할 변수

    // 두 수 중 하나가 0이 될 때까지 반복
    while(num1 != 0 && num2 != 0) {
        // num1이 num2보다 크거나 같으면 num1에서 num2를 뺍니다.
        if(num1 >= num2) {
            num1 -= num2;
        }
        // 그렇지 않으면 num2에서 num1을 뺍니다.
        else {
            num2 -= num1;
        }
        operation++;  // 연산 횟수 증가
    }
    return operation;  // 연산 횟수 반환
}

// int main() {
//     int num1, num2;

//     // 두 수를 입력 받습니다.
//     printf("첫 번째 숫자를 입력하세요: ");
//     scanf("%d", &num1);
//     printf("두 번째 숫자를 입력하세요: ");
//     scanf("%d", &num2);

//     // 연산 횟수를 계산하고 결과를 출력합니다.
//     int result = countOperations(num1, num2);
//     printf("연산 횟수: %d\n", result);

//     return 0;
// }
