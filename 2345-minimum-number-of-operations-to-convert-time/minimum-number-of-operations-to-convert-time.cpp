#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int convertTime(string a, string b) {
        // 문자열에서 시간과 분을 분리하여 정수로 변환
        int x = a[0] - '0', y = a[1] - '0', z = a[3] - '0', w = a[4] - '0';
        int p = b[0] - '0', q = b[1] - '0', r = b[3] - '0', s = b[4] - '0';

        // 시간과 분을 합쳐서 총 분으로 표현
        int hr1 = (x) * 10 + (y);
        int m1 = (z) * 10 + (w);
        int hr2 = (p) * 10 + (q);
        int m2 = (r) * 10 + s;
        int num1 = hr1 * 60 + m1;
        int num2 = hr2 * 60 + m2;

        // 두 시간 사이의 차이를 분으로 계산
        int diff = num2 - num1;

        int res = 0;
        // 버튼의 값 (각 버튼은 몇 분을 나타내는지)
        int arr[4] = {60, 15, 5, 1};

        // 각 버튼을 사용하여 시간 차이를 줄이는 최소 클릭 수를 계산
        for(int i = 0; i < 4; i++){
            res += diff / arr[i];
            diff = diff % arr[i];
        }
        return res;  // 필요한 총 클릭 수 반환
    }
};

// int main() {
//     Solution sol;
//     string time1 = "12:15";
//     string time2 = "13:20";
//     int result = sol.convertTime(time1, time2);
//     cout << "필요한 최소 버튼 클릭 수: " << result << endl;
//     return 0;
// }
