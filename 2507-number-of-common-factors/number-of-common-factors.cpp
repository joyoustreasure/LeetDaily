#include <iostream>

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int cf = 0;
        int m = (a < b) ? a : b; // 두 수 중 작은 수를 m에 저장
        for(int i = 1; i <= m; i++) {
            if(a % i == 0 && b % i == 0)
                cf++;
        }
        return cf;
    }
};

// int main() {
//     Solution sol;
//     int a, b;

//     cout << "두 정수를 입력하세요: ";
//     cin >> a >> b;

//     int result = sol.commonFactors(a, b);
//     cout << a << "와 " << b << "의 공통 약수의 개수는 " << result << "개 입니다." << endl;

//     return 0;
// }
