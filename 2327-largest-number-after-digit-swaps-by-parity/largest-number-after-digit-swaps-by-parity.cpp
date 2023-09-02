#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 주어진 숫자에서 홀수와 짝수를 분리하여 내림차순으로 정렬한 후, 원래 순서에 따라 합쳐서 반환하는 함수
    int largestInteger(int num) {
        string s = to_string(num); // 숫자를 문자열로 변환
        string ans;
        int i, j=0, k=0;
        vector<int> even; // 짝수를 저장할 벡터
        vector<int> odd;  // 홀수를 저장할 벡터

        // 문자열의 각 문자를 홀수와 짝수로 분리하여 저장
        for(i=0 ; i<s.size() ; i++)
        {
            if((int)s[i]%2==0)
                even.push_back((int)s[i]);
            else
                odd.push_back((int)s[i]);
        }

        // 홀수와 짝수 벡터를 내림차순으로 정렬
        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());

        // 원래 순서에 따라 홀수와 짝수를 합침
        for(i=0 ; i<s.size() ; i++)
        {
            if((int)s[i]%2==0)
            {
                ans += even[j];
                j++;
            }
            else
            {
                ans += odd[k];
                k++;
            }
        }
        return stoi(ans); // 합쳐진 문자열을 숫자로 변환하여 반환
    }
};

// int main() {
//     Solution solution;
//     int num;

//     cout << "숫자를 입력하세요: ";
//     cin >> num;

//     cout << "변환된 숫자: " << solution.largestInteger(num) << endl;

//     return 0;
// }
