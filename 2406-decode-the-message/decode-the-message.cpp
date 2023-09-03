#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // 주어진 키를 사용하여 메시지 디코딩
    string decodeMessage(string key, string message) {
        // 변환 테이블 초기화
        vector<int> table(26, -1);
        for (int i = 0, k = 0; i < key.size(); i++) {
            // 키 문자가 처음 나타나면 테이블에 추가
            if (key[i] != ' ' && table[key[i]-'a'] == -1) {
                table[key[i]-'a'] = k++;
            }
        }
        // 메시지 디코딩
        for (int i = 0; i < message.size(); i++) {
            if (message[i] != ' ') {
                message[i] = table[message[i]-'a'] + 'a';
            }
        }  
        return message;
    }
};

// int main() {
//     Solution solution;
//     string key, message;

//     cout << "디코딩 키를 입력하세요: ";
//     getline(cin, key);

//     cout << "디코딩할 메시지를 입력하세요: ";
//     getline(cin, message);

//     string decoded = solution.decodeMessage(key, message);
//     cout << "디코딩된 메시지: " << decoded << endl;

//     return 0;
// }
