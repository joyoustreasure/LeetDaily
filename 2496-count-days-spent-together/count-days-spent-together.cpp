#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    // 날짜를 입력받아 해당 날짜까지의 총 날짜 수를 반환하는 함수
    int getDate(const string& date) {
        int monthlist[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0, 2)); // 월 부분을 정수로 변환
        int days = stoi(date.substr(3, 2)); // 일 부분을 정수로 변환
        int sum = 0;
        for (int i = 1; i < month; i++) {
            sum += monthlist[i];
        }
        return sum + days;
    }

public:
    int countDaysTogether(const string& arriveAlice, const string& leaveAlice,
                          const string& arriveBob, const string& leaveBob) {
        int s = max(getDate(arriveAlice), getDate(arriveBob));
        int e = min(getDate(leaveAlice), getDate(leaveBob));
        return max(0, e - s + 1);
    }
};
