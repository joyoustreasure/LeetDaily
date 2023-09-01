#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 주어진 단어 목록에서 특정 접두사로 시작하는 단어의 개수를 반환하는 함수
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto x : words) {
            if(x.substr(0, pref.size()) == pref) {
                ans++;
            }
        }
        return ans;
    }
};

// int main() {
//     Solution solution;
//     vector<string> words = {"apple", "banana", "apricot", "appliance", "bat", "ape"};
//     string prefix;

//     // 접두사를 입력 받습니다.
//     cout << "접두사를 입력하세요: ";
//     cin >> prefix;

//     // 결과를 계산하고 출력합니다.
//     int result = solution.prefixCount(words, prefix);
//     cout << "주어진 단어 목록에서 " << prefix << "로 시작하는 단어의 개수: " << result << endl;

//     return 0;
// }
