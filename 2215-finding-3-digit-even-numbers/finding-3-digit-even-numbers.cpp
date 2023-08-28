#include <iostream>
#include <vector>

class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    // 주어진 숫자들의 빈도를 계산
    vector<int> count(10, 0);
    for (auto& d : digits) count[d]++;

    vector<int> res;  // 결과를 저장할 벡터

    //100부터 998까지 모든 짝수에 대해
    for (int num = 100; num < 999; num += 2) {
      //  현재 숫자의 빈도를 계산
      vector<int> currCount(10, 0);
      int temp = num;

      while (temp) {
        currCount[temp % 10]++;
        temp /= 10;
      }

      // 현재 숫자를 만들 수 있는지 여부를 확인
      bool flag = true;
      for (int i = 0; i < 10; i++) {
        if (currCount[i] > count[i]) {
          flag = false;
          break;
        }
      }

      // 만들 수 있다면 결과 벡터에 추가
      if (flag) {
        res.push_back(num);
      }
    }
    return res;  // 결과 반환
  }
};


// # int main() {
// #     Solution sol;
// #     vector<int> digits;
// #     int n, val;

// #     cout << "숫자의 개수를 입력하세요: ";
// #     cin >> n;

// #     cout << n << "개의 숫자를 입력하세요 (0-9 사이의 숫자): ";
// #     for (int i = 0; i < n; i++) {
// #         cin >> val;
// #         digits.push_back(val);
// #     }

// #     vector<int> evenNumbers = sol.findEvenNumbers(digits);
    
// #     cout << "3자리 짝수의 가능한 조합: ";
// #     for (int num : evenNumbers) {
// #         cout << num << " ";
// #     }
// #     cout << endl;

// #     return 0;
// # }
