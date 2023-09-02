#include <string>
using namespace std;

class Solution {
public:
    // 문자열 s에서 지정된 문자 letter의 출현 비율을 백분율로 반환하는 함수
    int percentageLetter(string s, char letter) {
        int count = 0; // letter의 출현 횟수를 저장할 변수

        // 문자열 s의 모든 문자를 반복하며 letter의 출현 횟수를 센다.
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == letter) {
                count++;
            }
        }

        // letter의 출현 비율을 백분율로 계산하여 반환
        return (count * 100) / s.length();
    }
};
