#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * capitalizeTitle(char * title) {
    int i = 0;
    int n = strlen(title);
    int j = 0;

    while(i < n) {
        j = i;
        int l = 0;

        // 현재 단어의 길이를 계산하고 모든 문자를 소문자로 변경
        while(i < n && title[i] != ' ') {
            title[i] = tolower(title[i]);
            i++;
            l++;
        }

        if(i > 0) {
            i++;
        }

        // 단어의 길이가 2보다 크면 첫 글자를 대문자로 변경
        if(l > 2) {
            title[j] = toupper(title[j]);
        }
    }

    return title;
}

// int main() {
//     char input[1000]; // 문자열 크기를 1000으로 가정. 필요에 따라 조절 가능.

//     printf("문자열을 입력하세요: ");
//     fgets(input, sizeof(input), stdin); // 사용자로부터 문자열 입력 받기
//     input[strcspn(input, "\n")] = '\0'; // fgets로 입력받은 문자열의 개행문자 제거

//     printf("%s\n", capitalizeTitle(input)); // 결과 출력

//     return 0;
// }
