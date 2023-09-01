#include <stdio.h>
#include <string.h>

// 주어진 단어 목록에서 특정 접두사로 시작하는 단어의 개수를 반환하는 함수
int prefixCount(char **words, int wordsSize, char *pref) {
    int ans = 0;
    int prefixLength = strlen(pref);
    
    for (int i = 0; i < wordsSize; i++) {
        if (strncmp(words[i], pref, prefixLength) == 0) {
            ans++;
        }
    }
    return ans;
}

// int main() {
//     char *words[] = {"apple", "banana", "apricot", "appliance", "bat", "ape"};
//     int wordsSize = sizeof(words) / sizeof(words[0]);
//     char prefix[100];

//     // 접두사를 입력 받습니다.
//     printf("접두사를 입력하세요: ");
//     scanf("%s", prefix);

//     // 결과를 계산하고 출력합니다.
//     int result = prefixCount(words, wordsSize, prefix);
//     printf("주어진 단어 목록에서 %s로 시작하는 단어의 개수: %d\n", prefix, result);

//     return 0;
// }
