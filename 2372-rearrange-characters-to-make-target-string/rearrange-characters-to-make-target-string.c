#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

int rearrangeCharacters(char *s, char *target) {
    int targetFreq[256] = {0}; // 타겟 문자열의 각 문자의 빈도수를 저장
    int sentFreq[256] = {0};   // 주어진 문자열의 각 문자의 빈도수를 저장
    
    // 타겟 문자열의 각 문자의 빈도수 계산
    for(int i = 0; target[i] != '\0'; i++) {
        targetFreq[(int)target[i]]++;
    }

    // 주어진 문자열의 각 문자의 빈도수 계산
    for(int i = 0; s[i] != '\0'; i++) {
        sentFreq[(int)s[i]]++;
    }

    int mn = INT_MAX; // 최소 빈도수 비율을 저장

    // 타겟 문자열의 각 문자에 대해 주어진 문자열에서 해당 문자의 빈도수와의 비율을 계산
    for(int i = 0; target[i] != '\0'; i++) {
        if (targetFreq[(int)target[i]] != 0) {
            mn = mn < (sentFreq[(int)target[i]] / targetFreq[(int)target[i]]) ? mn : (sentFreq[(int)target[i]] / targetFreq[(int)target[i]]);
        }
    }

    return mn;
}

// int main() {
//     char s[] = "aaabbbccc";
//     char target[] = "abc";

//     int result = rearrangeCharacters(s, target);
//     printf("문자열 '%s'에서 타겟 문자열 '%s'을 만들 수 있는 최대 횟수는 %d번 입니다.\n", s, target, result);

//     return 0;
// }
