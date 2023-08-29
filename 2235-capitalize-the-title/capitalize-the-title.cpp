#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 제목의 각 단어를 대문자로 시작하게 하는 함수
    // 단, 길이가 2 이하인 단어는 대문자로 시작하지 않음
    string capitalizeTitle(string s) {
        int i=0;
        int n=s.size();
        int j=0;

        // 문자열을 순회하면서 공백(' ')을 만날 때까지의 단어를 확인
        while(i<n){
            j=i;
            int l=0;
            // 현재 단어의 길이를 계산하고 모든 문자를 소문자로 변경
            while(i<n and s[i]!=' ') s[i]=tolower(s[i]), i++, l++;
            if(i>0)
            i++;

            // 단어의 길이가 2보다 크면 첫 글자를 대문자로 변경
            if(l>2){
                s[j]=toupper(s[j]);
            }   
        }
        return s;
    }
};

// int main() {
//     Solution solution;
//     string input;
//     cout << "문자열을 입력하세요: ";
//     getline(cin, input); // 사용자로부터 문자열 입력 받기
//     cout << solution.capitalizeTitle(input) << endl; // 결과 출력
//     return 0;
// }
