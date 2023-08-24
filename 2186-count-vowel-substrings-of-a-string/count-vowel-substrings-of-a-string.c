#include <stdbool.h>
#include <string.h>

int countVowelSubstrings(char* w) {
    int vow = 0, cnt = 0, m[123] = {};  // vow: 모음의 수, cnt: 결과 값, m: 각 문자의 발생 횟수를 저장하는 배열
    char* vowels = "aeiou";  // 모음 문자열
    int length = strlen(w);  // 입력 문자열의 길이 계산
    for (int i = 0, j = 0, k = 0; i < length; ++i) {
        // 현재 문자가 모음인 경우
        if (strchr(vowels, w[i])) {
            vow += ++m[(int)w[i]] == 1;  // 해당 모음의 발생 횟수 증가
            // 모든 모음이 존재하는 경우
            for (; vow == 5; ++k)
                vow -= --m[(int)w[k]] == 0;  // 모음 발생 횟수 감소
            cnt += k - j;  // 결과 값 갱신
        }
        // 현재 문자가 자음인 경우
        else {
            m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0;  // 초기화
            j = k = i + 1;  // 인덱스 갱신
        }
    }
    return cnt;  // 결과 값 반환
}
