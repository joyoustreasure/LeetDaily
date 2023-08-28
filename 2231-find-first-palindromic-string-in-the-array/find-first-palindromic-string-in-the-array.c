#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool check(const char* s) {
    int l = 0, h = strlen(s) - 1;
    while(l < h) {
        if(s[l++] != s[h--])
            return false;
    }
    return true;
}

char* firstPalindrome(char** words, int wordsSize) {
    for(int i = 0; i < wordsSize; i++) {
        if(check(words[i]))
            return words[i];
    }
    return "";
}

// int main() {
//     int n;
//     printf("단어의 개수를 입력하세요: ");
//     scanf("%d", &n);

//     char* words[n];
//     printf("단어들을 입력하세요:\n");
//     for(int i = 0; i < n; i++) {
//         words[i] = (char*)malloc(100 * sizeof(char));  // 각 단어의 최대 길이를 100으로 가정
//         scanf("%s", words[i]);
//     }

//     char* result = firstPalindrome(words, n);
//     if(strlen(result) != 0) {
//         printf("첫 번째 회문: %s\n", result);
//     } else {
//         printf("회문이 없습니다.\n");
//     }

//     for(int i = 0; i < n; i++) {
//         free(words[i]);
//     }

//     return 0;
// }
