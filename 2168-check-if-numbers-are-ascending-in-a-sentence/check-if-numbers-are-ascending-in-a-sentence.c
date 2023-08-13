#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool areNumbersAscending(char *s) {
    int nums[100];   // 숫자를 저장할 배열을 생성합니다. (100은 최대 숫자 개수 예상값입니다.)
    int numsCount = 0; // 숫자 개수를 추적합니다.
    int i = 0;
    
    while (s[i] != '\0') {
        if (isDigit(s[i])) { // 현재 문자가 숫자인지 확인합니다.
            char temp[20];   // 숫자를 임시로 저장할 문자열을 생성합니다. (20은 최대 자릿수 예상값입니다.)
            int tempIndex = 0;
            
            while (s[i] != '\0' && isDigit(s[i])) {
                temp[tempIndex++] = s[i++]; // 연속된 숫자들을 임시 문자열에 추가합니다.
            }
            temp[tempIndex] = '\0'; // 문자열을 끝을 나타내는 널 문자로 끝냅니다.
            
            nums[numsCount++] = atoi(temp); // 문자열을 정수로 변환하여 배열에 저장합니다.
        } else {
            ++i;
        }
    }
    
    for (i = 0; i < numsCount - 1; ++i) {
        if (nums[i] >= nums[i + 1]) {
            return false; // 숫자들을 순회하며 인접한 숫자가 내림차순인 경우 false를 반환합니다.
        }
    }
    
    return true; // 모든 숫자들이 오름차순이라면 true를 반환합니다.
}

