#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool digitCount(char *num) {
    int mp[10] = {0}; // 0부터 9까지의 숫자에 대한 빈도를 저장하기 위한 배열

    // 각 숫자의 빈도를 계산
    for (int i = 0; i < strlen(num); i++) {
        mp[num[i] - '0']++;
    }

    // 주어진 숫자의 빈도와 해당 숫자가 일치하는지 확인
    for (int i = 0; i < strlen(num); i++) {
        if (mp[i] != (num[i] - '0')) {
            return false;
        }
    }
    return true;
}

// int main() {
//     char num[] = "1210";

//     bool result = digitCount(num);
//     if(result) {
//         printf("The number string %s satisfies the condition.\n", num);
//     } else {
//         printf("The number string %s does not satisfy the condition.\n", num);
//     }

//     return 0;
// }
