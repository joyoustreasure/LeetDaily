#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 주어진 문자열 s와 거리 배열 distance에 대해
    // 문자열 내의 모든 문자 쌍의 거리가 distance 배열과 일치하는지 확인
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();

        // 문자열 내의 모든 문자를 확인
        for(int i = 0; i < n; i++) {
            // 현재 문자와 같은 다른 문자를 찾음
            for(int j = i + 1; j < n; j++) {
                if(s[i] == s[j]) {
                    // 두 문자 사이의 거리가 distance 배열과 일치하는지 확인
                    if(j - i - 1 != distance[s[i] - 'a']) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// int main() {
//     Solution sol;
//     string s = "abcdea";
//     vector<int> distance = {5, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//     if (sol.checkDistances(s, distance)) {
//         cout << "True: The distances match the given array." << endl;
//     } else {
//         cout << "False: The distances do not match the given array." << endl;
//     }

//     return 0;
// }
