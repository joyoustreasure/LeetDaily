#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDigit(char* number, char digit) {
    int n = strlen(number);
    char temp[n]; 
    char *maxStr = (char*)malloc(sizeof(char) * (n + 1)); // 동적 할당으로 결과 문자열 저장용
    maxStr[0] = '\0'; 

    // number 문자열의 각 문자를 확인
    for(int i = 0; i < n; i++) {
        if(number[i] == digit) {
            // digit를 제외하고 새 문자열 생성
            strncpy(temp, number, i);
            strcpy(temp + i, number + i + 1);
            
            // maxStr 업데이트
            if(strcmp(temp, maxStr) > 0) {
                strcpy(maxStr, temp);
            }
        }
    }
    
    return maxStr; // 결과 문자열 반환
}

// int main() {
//     char number[] = "123241";
//     char digit = '2';

//     char *result = removeDigit(number, digit);
//     printf("숫자를 제거한 후 가장 큰 문자열: %s\n", result);

//     free(result); // 동적 할당된 메모리 해제

//     return 0;
// }
