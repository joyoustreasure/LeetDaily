#include <stdio.h>
#include <string.h>

int countPoints(char *rings) {
    // 각 색상의 반지 개수를 저장하기 위한 배열 초기화
    int r[10] = {0};
    int g[10] = {0};
    int b[10] = {0};
    
    int len = strlen(rings);
    int rod;
    for(int i = 0; i < len; i += 2) {
        // 문자를 정수로 변환
        rod = rings[i + 1] - '0';
        
        // 반지가 어디에 있는지 해당 색상 배열에 추가
        if(rings[i] == 'R') {
            r[rod]++;
        } else if(rings[i] == 'G') {
            g[rod]++;
        } else if(rings[i] == 'B') {
            b[rod]++;
        }
    }
    
    // 세 가지 색상의 반지가 모두 존재하면 카운트 증가
    int count = 0;
    for(int j = 0; j < 10; j++) {
        if(r[j] > 0 && g[j] > 0 && b[j] > 0) {
            count++;
        }
    }
    
    return count;
}

// int main() {
//     char rings[21];  // 최대 10개의 위치와 색상 정보를 저장하기 위한 배열

//     printf("반지 문자열을 입력하세요 (예: R1G1B1): ");
//     scanf("%s", rings);

//     int result = countPoints(rings);
//     printf("세 가지 색상의 반지가 모두 있는 위치 개수: %d\n", result);

//     return 0;
// }
