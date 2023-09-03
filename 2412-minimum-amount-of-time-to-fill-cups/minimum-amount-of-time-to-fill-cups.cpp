#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper function to sort the amounts in ascending order
    void sortCups(vector<int>& amount) {
        for (int i = 0; i < amount.size() - 1; i++) {
            for (int j = i + 1; j < amount.size(); j++) {
                if (amount[i] > amount[j]) {
                    swap(amount[i], amount[j]);
                }
            }
        }
    }

    int fillCups(vector<int>& amount) {
        int result = 0;

        // 오름차순으로 정렬
        sortCups(amount);

        // 가장 큰 두 컵에 물이 있을 동안 계속 실행
        while (amount[1] && amount[2]) {
            // 1초 동안 두 컵에 물을 채우기
            result++;
            amount[1]--;
            amount[2]--;
            // 계속해서 가장 큰 컵이 뒤에 오도록 정렬
            sortCups(amount);
        }

        // 가장 큰 컵에 남아있는 물의 양만큼 시간 추가
        result += amount[2];

        return result;
    }
};

// int main() {
//     Solution solution;
//     vector<int> amount(3);

//     cout << "세 컵에 필요한 물의 양을 입력하세요: ";
//     for (int i = 0; i < 3; i++) {
//         cin >> amount[i];
//     }

//     int result = solution.fillCups(amount);
//     cout << "필요한 최소 시간: " << result << "초" << endl;

//     return 0;
// }
