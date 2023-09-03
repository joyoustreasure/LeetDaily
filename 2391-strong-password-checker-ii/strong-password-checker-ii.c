#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool strongPasswordCheckerII(char *password) {
    // 비밀번호 길이가 8 미만이면 false 반환
    if(strlen(password) < 8) return false;
    
    // 각각의 조건들을 나타내는 변수들
    bool low = false, upper = false, digit = false, special = false;
    
    // 문자열의 각 문자들을 순회하며 조건 체크
    for(int i = 0; password[i]; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') low = true;
        else if(password[i] >= 'A' && password[i] <= 'Z') upper = true;
        else if(isdigit(password[i])) digit = true;
        else special = true;
    }
    
    // 6번째 조건: 연속된 같은 문자가 없어야 함
    for(int i = 0; i+1 < strlen(password); i++) {
        if(password[i] == password[i+1]) return false;
    }
    
    // 모든 조건을 만족하면 true, 아니면 false 반환
    if(low && upper && digit && special) return true;
    return false;
}

// int main() {
//     char password[100];

//     printf("비밀번호를 입력하세요: ");
//     scanf("%s", password);

//     if(strongPasswordCheckerII(password)) {
//         printf("강력한 비밀번호입니다.\n");
//     } else {
//         printf("약한 비밀번호입니다.\n");
//     }

//     return 0;
// }
