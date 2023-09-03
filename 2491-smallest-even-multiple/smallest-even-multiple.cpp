#include <iostream>
using namespace std;

class Solution {
public:
    // 주어진 정수 n에 대해 가장 작은 짝수 배를 반환하는 함수
    int smallestEvenMultiple(int n) {
        if(n % 2 == 0) // n이 짝수인 경우
            return n;
        else  // n이 홀수인 경우
        {
            return n * 2;
        }
    }
};

// int main() {
//     Solution sol;
//     int num;
//     cout << "정수를 입력하세요: ";
//     cin >> num;
//     cout << num << "의 가장 작은 짝수 배는 " << sol.smallestEvenMultiple(num) << "입니다." << endl;
//     return 0;
// }
