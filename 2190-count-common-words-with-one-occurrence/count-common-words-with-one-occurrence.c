#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 해시 테이블에 사용될 구조체 정의
typedef struct {
    char name[31];            // 문자열을 저장하기 위한 배열
    int count;                // 해당 문자열의 개수
    UT_hash_handle hh;        // 해시 테이블 핸들
} WordHash;

#define WORD1_DUPLICATED 1000  // `words1`에 중복된 문자열을 표시하기 위한 상수

int countWords(char ** words1, int words1Size, char ** words2, int words2Size){
    int ans = 0;   // 결과값을 저장하기 위한 변수

    WordHash* h = NULL;   // 해시 테이블의 헤더
    WordHash* d = NULL;
    
    // `words1`에 있는 모든 문자열을 해시 테이블에 추가
    for(int i = 0; i < words1Size; i++){
        // 현재 문자열이 이미 해시 테이블에 있는지 확인
        HASH_FIND_STR(h, words1[i], d);
        if(d){
            // 이미 있다면 중복으로 표시
            d->count = WORD1_DUPLICATED;
        }
        else{
            // 없다면 새로운 항목을 추가
            WordHash* p = (WordHash*)calloc(1, sizeof(WordHash));
            strcpy(p->name, words1[i]);
            p->count = 1;
            HASH_ADD_STR(h, name, p);         
        }
    }
    
    // `words2`에 있는 모든 문자열을 확인
    for(int i = 0; i < words2Size; i++){
        // 현재 문자열이 `words1`에 있는지 확인
        HASH_FIND_STR(h, words2[i], d);
        if(d){
            d->count++;
            if(d->count == 2)
                ans++;
            else if(d->count == 3)
                ans--;
        }
    }    
    return ans;   // 결과값 반환
}
