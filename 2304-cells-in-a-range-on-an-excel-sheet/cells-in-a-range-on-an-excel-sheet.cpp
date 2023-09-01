#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 주어진 범위 내의 모든 셀을 반환하는 함수
    vector<string> cellsInRange(string s) {
        vector<string> ans;  // 결과를 저장할 벡터
        
        // 첫 번째 열부터 마지막 열까지 반복
        for(char ch = s[0]; ch <= s[3]; ch++) {
            // 첫 번째 행부터 마지막 행까지 반복
            for(int i = s[1]-'0'; i <= s[4]-'0'; i++) {
                string res = "";  // 셀을 저장할 문자열 초기화
                res += ch;  // 열 추가
                res += to_string(i);  // 행 추가
                ans.push_back(res);  // 결과 벡터에 셀 추가
            }
        }
        return ans;  // 결과 반환
    }
};

// int main() {
//     Solution solution;
//     string range;

//     // 범위를 입력 받습니다.
//     cout << "셀의 범위를 입력하세요 (예: A1:B2): ";
//     cin >> range;

//     // 결과를 계산하고 출력합니다.
//     vector<string> result = solution.cellsInRange(range);
//     cout << "해당 범위의 셀 목록:" << endl;
//     for (const string& cell : result) {
//         cout << cell << " ";
//     }

//     return 0;
// }
