#include <stdio.h>
#include <string.h>

int countAsterisks(char *s) {
    int further = 0;  // '|' 문자를 발견했는지 여부 (0: 발견 안함, 1: 첫 번째 '|' 발견, 2: 두 번째 '|' 발견)
    int count = 0;    // '*' 문자의 개수

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '|' && further == 0)  // 첫 번째 '|' 문자를 발견했을 때
            further = 1;
        else if (s[i] == '|' && further == 1)  // 두 번째 '|' 문자를 발견했을 때
            further = 0;
        else if (s[i] == '*' && further == 0)  // '|' 문자 사이가 아닌 '*' 문자를 발견했을 때
            count++;
    }
    return count;
}

// int main() {
//     char s[100];

//     printf("문자열을 입력하세요: ");
//     scanf("%s", s);

//     int result = countAsterisks(s);
//     printf("문자열 내 '|' 문자 사이가 아닌 '*' 문자의 개수는 %d개 입니다.\n", result);

//     return 0;
// }
