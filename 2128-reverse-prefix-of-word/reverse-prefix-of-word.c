#include <stdio.h>
#include <string.h>

char * reversePrefix(char * word, char ch) {
    int len = strlen(word);
    int index = -1; // 문자 위치 인덱스

    // 문자 위치 찾기
    for (int i = 0; i < len; ++i) {
        if (word[i] == ch) {
            index = i;
            break;
        }
    }

    // 문자를 찾지 못한 경우 원래 문자열 반환
    if (index == -1) {
        return word;
    }

    // 문자열 뒤집기
    for (int i = 0; i <= index / 2; ++i) {
        char temp = word[i];
        word[i] = word[index - i];
        word[index - i] = temp;
    }

    return word;
}
