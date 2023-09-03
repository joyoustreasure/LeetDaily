#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 문자열 내의 '*' 문자의 개수를 세는 함수
    int countAsterisks(string s) {
        bool further = false;  // '|' 문자를 발견했는지 여부
        int count = 0;         // '*' 문자의 개수

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '|' && further == false)  // 첫 번째 '|' 문자를 발견했을 때
                further = true;
            else if (s[i] == '|' && further == true)  // 두 번째 '|' 문자를 발견했을 때
                further = false;
            else if (s[i] == '*' && further == false)  // '|' 문자 사이가 아닌 '*' 문자를 발견했을 때
                count++;
        }
        return count;
    }
};

// int main() {
//     Solution solution;
//     string s;

//     cout << "문자열을 입력하세요: ";
//     cin >> s;

//     int result = solution.countAsterisks(s);
//     cout << "문자열 내 '|' 문자 사이가 아닌 '*' 문자의 개수는 " << result << "개 입니다." << endl;

//     return 0;
// }
// class Solution {
// public:
//     int countAsterisks(string s) {
        
//     }
// };