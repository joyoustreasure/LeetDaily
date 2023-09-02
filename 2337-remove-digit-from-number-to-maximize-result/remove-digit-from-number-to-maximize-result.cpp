#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 주어진 숫자 문자열에서 특정 숫자를 제거한 후 가장 큰 문자열 반환
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<string> ans;
        
        // number 문자열의 각 문자를 확인
        for(int i = 0; i < n; i++) {
            if(number[i] == digit) {
                // digit를 제외하고 새 문자열 생성
                string res = number.substr(0, i) + number.substr(i + 1, n - i - 1);
                ans.push_back(res);
            }
        }

        // ans 벡터에서 사전순으로 가장 큰 문자열 찾기
        string maxStr = "";
        for(string s : ans) {
            if(s > maxStr) maxStr = s;
        }
        
        return maxStr;
    }
};

// int main() {
//     Solution solution;
//     string number = "123241";
//     char digit = '2';
    
//     cout << "숫자를 제거한 후 가장 큰 문자열: " << solution.removeDigit(number, digit) << endl;

//     return 0;
// }
