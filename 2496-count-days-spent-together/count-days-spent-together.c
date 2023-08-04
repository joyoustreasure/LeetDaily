#include <stdio.h>
#include <stdlib.h>

// 날짜를 입력받아 해당 날짜까지의 총 날짜 수를 반환하는 함수
int getDate(char* date) {
    int monthlist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = atoi(date); // 문자열에서 월 부분을 정수로 변환
    int days = atoi(date + 3); // 문자열에서 일 부분을 정수로 변환
    int sum = 0;
    for (int i = 1; i < month; i++) {
        sum += monthlist[i]; // 해당 월 이전까지의 일 수를 누적
    }
    return sum + days; // 해당 월의 일 수와 일 수를 합하여 총 날짜 수 반환
}

// Alice와 Bob이 함께 있는 최대 날짜 수를 계산하는 함수
int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    // Alice와 Bob의 도착 날짜 중 더 늦은 날짜를 선택
    int s = (getDate(arriveAlice) > getDate(arriveBob)) ? getDate(arriveAlice) : getDate(arriveBob);
    // Alice와 Bob의 출발 날짜 중 더 이른 날짜를 선택
    int e = (getDate(leaveAlice) < getDate(leaveBob)) ? getDate(leaveAlice) : getDate(leaveBob);
    // 최대 날짜 수를 계산하고, 음수인 경우 0으로 처리하여 반환
    return (e - s + 1 > 0) ? (e - s + 1) : 0;
}
