#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        // 비밀번호 길이가 8 미만이면 false 반환
        if(size(p) < 8) return false;
        
        // 각각의 조건들을 나타내는 변수들
        bool low = false, upper = false, digit = false, special = false;
        
        // 문자열의 각 문자들을 순회하며 조건 체크
        for(auto c : p){
            if(c >= 'a' && c <= 'z') low = true;
            else if(c >= 'A' && c <= 'Z') upper = true;
            else if(isdigit(c)) digit = true;
            else special = true;
        }
        
        // 6번째 조건: 연속된 같은 문자가 없어야 함
        for(int i = 0; i+1 < size(p); i++) {
            if(p[i] == p[i+1]) return false;
        }
        
        // 모든 조건을 만족하면 true, 아니면 false 반환
        if(low && upper && digit && special) return true;
        return false;
    }
};

// int main() {
//     Solution solution;
//     string password;

//     cout << "비밀번호를 입력하세요: ";
//     cin >> password;

//     if(solution.strongPasswordCheckerII(password)) {
//         cout << "강력한 비밀번호입니다." << endl;
//     } else {
//         cout << "약한 비밀번호입니다." << endl;
//     }

//     return 0;
// }
