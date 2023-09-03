#include <stdio.h>

double calculateTax(int** brackets, int bracketsSize, int* bracketsColSize, int income) {
    double tax = 0;

    // 첫 번째 세율 구간 처리
    if (brackets[0][0] <= income) {
        tax = (brackets[0][0] * brackets[0][1] / 100.0);
    } else {
        return (income * brackets[0][1] / 100.0);
    }

    // 나머지 세율 구간 처리
    for (int i = 1; i < bracketsSize; i++) {
        if (brackets[i][0] <= income) {
            tax += ((brackets[i][0] - brackets[i-1][0]) * brackets[i][1] / 100.0);
        } else {
            tax += ((income - brackets[i-1][0]) * brackets[i][1] / 100.0);
            break;
        }
    }

    return tax;
}

// int main() {
//     int bracketsSize;
//     int* bracketsColSize;
//     int** brackets;
//     int income;

//     printf("세율 구간의 수를 입력하세요: ");
//     scanf("%d", &bracketsSize);

//     brackets = (int**)malloc(bracketsSize * sizeof(int*));
//     bracketsColSize = (int*)malloc(bracketsSize * sizeof(int));

//     printf("세율 구간을 입력하세요 (예: 5000 10 은 5000까지 10%%의 세금):\n");
//     for (int i = 0; i < bracketsSize; i++) {
//         brackets[i] = (int*)malloc(2 * sizeof(int));
//         bracketsColSize[i] = 2;
//         for (int j = 0; j < 2; j++) {
//             scanf("%d", &brackets[i][j]);
//         }
//     }

//     printf("소득을 입력하세요: ");
//     scanf("%d", &income);

//     double tax = calculateTax(brackets, bracketsSize, bracketsColSize, income);
//     printf("세금은 %.2f 입니다.\n", tax);

//     // 메모리 해제
//     for (int i = 0; i < bracketsSize; i++) {
//         free(brackets[i]);
//     }
//     free(brackets);
//     free(bracketsColSize);

//     return 0;
// }
