#include <iostream>
#include <string>
#include <unordered_map> // unordered_map을 사용하기 위한 헤더
#include <climits>       // INT_MAX를 사용하기 위한 헤더
using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> targetFreq; // 타겟 문자열의 각 문자의 빈도수를 저장
        
        // 타겟 문자열의 각 문자의 빈도수 계산
        for(auto a : target) {
            targetFreq[a]++;
        }

        unordered_map<char, int> sentFreq; // 주어진 문장의 각 문자의 빈도수를 저장

        // 주어진 문장의 각 문자의 빈도수 계산
        for(auto a : s) {
            sentFreq[a]++;
        }

        int mn = INT_MAX; // 최소 빈도수 비율을 저장

        // 타겟 문자열의 각 문자에 대해 주어진 문장에서 해당 문자의 빈도수와의 비율을 계산
        for(auto a : targetFreq) {
            mn = min(mn, sentFreq[a.first] / a.second);
        }

        return mn;
    }
};

// int main() {
//     Solution solution;
//     string s = "aaabbbccc";
//     string target = "abc";

//     int result = solution.rearrangeCharacters(s, target);
//     cout << "문자열 '" << s << "'에서 타겟 문자열 '" << target 
//          << "'을 만들 수 있는 최대 횟수는 " << result << "번 입니다." << endl;

//     return 0;
// }
