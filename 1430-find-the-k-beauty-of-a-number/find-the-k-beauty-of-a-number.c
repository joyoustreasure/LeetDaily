#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// s2로 변환된 정수로 s1로 변환된 정수를 나누었을 때 나머지가 0인지 확인합니다.
int isBeauty(char* s1, char* s2) {
    int n1 = atoi(s1);
    int n2 = atoi(s2);
    if (n2) return !(n1 % n2);
    return 0;
}

// 주어진 숫자에서 k 길이의 모든 부분 문자열을 추출하고 해당 부분 문자열이 원래 숫자의 약수인지 확인합니다.
int divisorSubstrings(int num, int k) {
    char s[20]; // 충분히 큰 크기로 설정합니다.
    sprintf(s, "%d", num);
    int n = strlen(s);
    if (!n) return 0;
    
    int i = 0, j = 0, beautyCount = 0;
    char window[20];

    while (j < n) {
        strncpy(window, s + i, j - i + 1);
        window[j - i + 1] = '\0';

        if (j - i + 1 < k) {
            j++;
        } else if (j - i + 1 == k) {
            if (isBeauty(s, window)) beautyCount++;
            i++;
            j++;
        }
    }
    
    return beautyCount;
}

// int main() {
//     int num = 120;
//     int k = 2;
//     printf("약수인 부분 문자열의 개수: %d\n", divisorSubstrings(num, k));
//     return 0;
// }
