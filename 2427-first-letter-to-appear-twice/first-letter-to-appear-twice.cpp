#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        // 알파벳의 빈도를 저장할 벡터 초기화
        vector<int> v(26, 0);
        
        for(char c : s) {
            // 문자의 빈도를 증가시키고, 빈도가 2가 되면 해당 문자를 반환
            v[c - 'a']++;
            if(v[c - 'a'] > 1) {
                return c;
            }
        }
        
        // 반복되는 문자가 없는 경우 'a' 반환
        return 'a';
    }
};

// int main() {
//     Solution solution;
//     string input;
    
//     cout << "문자열을 입력하세요: ";
//     cin >> input;

//     char result = solution.repeatedCharacter(input);
//     if(result == 'a') {
//         cout << "반복되는 문자가 없습니다." << endl;
//     } else {
//         cout << "처음으로 반복되는 문자: " << result << endl;
//     }

//     return 0;
// }
