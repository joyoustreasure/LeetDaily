#include <stdio.h>
#include <string.h>

char repeatedCharacter(char *s) {
    // 알파벳의 빈도를 저장할 배열 초기화
    int v[26] = {0};
    
    int length = strlen(s);
    for(int i = 0; i < length; i++) {
        char c = s[i];
        // 문자의 빈도를 증가시키고, 빈도가 2가 되면 해당 문자를 반환
        v[c - 'a']++;
        if(v[c - 'a'] > 1) {
            return c;
        }
    }
    
    // 반복되는 문자가 없는 경우 'a' 반환
    return 'a';
}

// int main() {
//     char input[100];

//     printf("문자열을 입력하세요: ");
//     scanf("%s", input);

//     char result = repeatedCharacter(input);
//     if(result == 'a') {
//         printf("반복되는 문자가 없습니다.\n");
//     } else {
//         printf("처음으로 반복되는 문자: %c\n", result);
//     }

//     return 0;
// }
