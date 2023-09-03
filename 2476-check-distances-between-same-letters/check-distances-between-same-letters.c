#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool checkDistances(char * s, int* distance, int distanceSize) {
    int n = strlen(s);

    // 문자열 내의 모든 문자를 확인
    for(int i = 0; i < n; i++) {
        // 현재 문자와 같은 다른 문자를 찾음
        for(int j = i + 1; j < n; j++) {
            if(s[i] == s[j]) {
                // 두 문자 사이의 거리가 distance 배열과 일치하는지 확인
                if(j - i - 1 != distance[s[i] - 'a']) {
                    return false;
                }
            }
        }
    }
    return true;
}

// int main() {
//     char s[] = "abcdea";
//     int distance[] = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//     int distanceSize = sizeof(distance) / sizeof(distance[0]);

//     if (checkDistances(s, distance, distanceSize)) {
//         printf("True: The distances match the given array.\n");
//     } else {
//         printf("False: The distances do not match the given array.\n");
//     }

//     return 0;
// }
