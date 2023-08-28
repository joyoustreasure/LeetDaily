#include <stdio.h>
#include <string.h>

int mostWordsFound(char** sentences, int sentencesSize) {
    int counter, ans = 0;
    // 모든 문장에 대해 반복
    for(int i = 0; i < sentencesSize; i++) {
        int k = strlen(sentences[i]);
        counter = 1;  // 단어의 개수를 세는 카운터. 하나의 문장에는 최소한 하나의 단어가 있으므로 시작값을 1로 설정
        // 각 문장의 모든 문자를 순회
        for(int j = 0; j < k; j++) {
            // 공백 문자를 발견하면 단어 카운터를 증가
            if(sentences[i][j] == ' ') {
                counter++;
            }
        }
        // 현재 문장의 단어 개수와 이전까지의 최대 단어 개수를 비교하여 최대값 업데이트
        ans = (counter > ans) ? counter : ans;
    }
    return ans;
}

// int main() {
//     int n;
//     printf("문장의 개수를 입력하세요: ");
//     scanf("%d", &n);
//     getchar();  // 버퍼에서 남아 있는 개행 문자를 제거

//     char* sentences[n];
//     printf("문장들을 입력하세요:\n");
//     for(int i = 0; i < n; i++) {
//         sentences[i] = (char*)malloc(1000 * sizeof(char));  // 각 문장의 최대 길이를 1000으로 가정
//         fgets(sentences[i], 1000, stdin);
//         sentences[i][strlen(sentences[i]) - 1] = '\0';  // 개행 문자 제거
//     }

//     int result = mostWordsFound(sentences, n);
//     printf("가장 많은 단어를 가진 문장의 단어 개수: %d\n", result);

//     for(int i = 0; i < n; i++) {
//         free(sentences[i]);
//     }

//     return 0;
// }
