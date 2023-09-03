#include <stdio.h>

// Helper function to sort the amounts in ascending order
void sortCups(int* amount, int amountSize) {
    for (int i = 0; i < amountSize - 1; i++) {
        for (int j = i + 1; j < amountSize; j++) {
            if (amount[i] > amount[j]) {
                int temp = amount[i];
                amount[i] = amount[j];
                amount[j] = temp;
            }
        }
    }
}

int fillCups(int* amount, int amountSize) {
    int result = 0;

    // 오름차순으로 정렬
    sortCups(amount, amountSize);

    // 가장 큰 두 컵에 물이 있을 동안 계속 실행
    while (amount[amountSize - 2] && amount[amountSize - 1]) {
        // 1초 동안 두 컵에 물을 채우기
        result++;
        amount[amountSize - 2]--;
        amount[amountSize - 1]--;
        // 계속해서 가장 큰 컵이 뒤에 오도록 정렬
        sortCups(amount, amountSize);
    }

    // 가장 큰 컵에 남아있는 물의 양만큼 시간 추가
    result += amount[amountSize - 1];

    return result;
}

// int main() {
//     int amount[3];

//     printf("세 컵에 필요한 물의 양을 입력하세요: ");
//     for (int i = 0; i < 3; i++) {
//         scanf("%d", &amount[i]);
//     }

//     int result = fillCups(amount, 3);
//     printf("필요한 최소 시간: %d초\n", result);

//     return 0;
// }
