#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool checkAlmostEquivalent(char* word1, char* word2) {
    // 문자의 빈도수를 저장하기 위한 배열을 생성하고 0으로 초기화합니다.
    int freq[26] = {0};

    // word1의 각 문자를 순회하면서 배열에서 해당 문자의 빈도수를 증가시킵니다.
    for(int i = 0; i < strlen(word1); i++){
        freq[word1[i] - 'a']++;
    }

    // word2의 각 문자를 순회하면서 배열에서 해당 문자의 빈도수를 감소시킵니다.
    for(int i = 0; i < strlen(word2); i++){
        freq[word2[i] - 'a']--;
    }

    // 배열의 문자 빈도수를 확인합니다.
    // 어떤 문자의 빈도수의 절대값이 3을 초과하면 두 단어는 "거의 동일"하지 않다고 판단합니다.
    for(int i = 0; i < 26; i++){
        if(abs(freq[i]) > 3){
            return false;
        }
    }

    // 두 단어는 "거의 동일"하다고 판단하고 true를 반환합니다.
    return true;
}
