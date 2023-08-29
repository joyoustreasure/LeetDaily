#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 문자열 s를 최대 크기 k의 부분 문자열로 나누는 함수
    // 마지막 부분 문자열의 크기가 k보다 작을 경우 fill 문자로 채운다.
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;

        // 문자열 s를 순회하면서 k 크기만큼의 부분 문자열을 생성한다.
        for(int i = 0; i < s.size(); i = i + k) {
            string t = s.substr(i, k);  // 크기가 최대 k인 부분 문자열 생성

            if(t.size() == k) {  // 부분 문자열의 크기가 k이면 바로 결과에 추가
                v.push_back(t);
                continue;
            }

            // 부분 문자열의 크기가 k보다 작을 경우 fill 문자로 채운다.
            int l = t.size();
            for(int j = 0; j < (k - l); j++)
                t += fill;

            v.push_back(t);
        }

        return v;
    }
};

// int main() {
//     Solution solution;

//     string input;
//     int k;
//     char fill;

//     cout << "문자열을 입력하세요: ";
//     getline(cin, input);

//     cout << "부분 문자열의 최대 크기를 입력하세요: ";
//     cin >> k;

//     cout << "부분 문자열을 채울 문자를 입력하세요: ";
//     cin >> fill;

//     vector<string> result = solution.divideString(input, k, fill);

//     cout << "결과: " << endl;
//     for(const string& str : result) {
//         cout << str << endl;
//     }

//     return 0;
// }
