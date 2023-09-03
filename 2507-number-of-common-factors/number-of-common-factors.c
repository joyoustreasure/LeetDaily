#include <stdio.h>

int commonFactors(int a, int b) {
    int cf = 0;
    int m = (a < b) ? a : b;
    for(int i = 1; i <= m; i++) {
        if(a % i == 0 && b % i == 0)
            cf++;
    }
    return cf;
}

// int main() {
//     int a, b;

//     printf("두 정수를 입력하세요: ");
//     scanf("%d %d", &a, &b);

//     int result = commonFactors(a, b);
//     printf("%d와 %d의 공통 약수의 개수는 %d개 입니다.\n", a, b, result);

//     return 0;
// }
