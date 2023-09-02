#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // s2로 변환된 정수로 s1로 변환된 정수를 나누었을 때 나머지가 0인지 확인합니다.
    bool isBeauty(string s1, string s2){
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        if(n2) return !(n1 % n2); // s2가 0이 아니면 n1 % n2가 0인지 확인
        return false;
    }
    
    // 주어진 숫자에서 k 길이의 모든 부분 문자열을 추출하고 해당 부분 문자열이 원래 숫자의 약수인지 확인합니다.
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        if(!n) return 0;
        int i = 0, j = 0, beautyCount = 0; // i, j는 슬라이딩 윈도우의 시작 및 끝을 나타냅니다.
        
        // 슬라이딩 윈도우 알고리즘을 사용
        while(j < n){
            // 윈도우 내의 부분 문자열을 계산
            string window = s.substr(i, j - i + 1);
            
            // 윈도우 크기가 k에 도달하지 않은 경우
            if(j - i + 1 < k){
                j++;
            }
            // 윈도우 크기가 k에 도달한 경우
            else if(j - i + 1 == k){
                // 해당 부분 문자열이 약수인지 확인
                if(isBeauty(s, window)) beautyCount++;
                
                // 슬라이딩 윈도우 이동
                i++;
                j++;
            }
        }
        return beautyCount;
    }
};

// int main() {
//     Solution sol;
//     int num = 120;
//     int k = 2;
//     cout << "약수인 부분 문자열의 개수: " << sol.divisorSubstrings(num, k) << endl;
//     return 0;
// }
