#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 주어진 행렬이 'X' 행렬인지 확인하는 함수
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 대각선인지 확인
                if (j == i || j == n-i-1) {
                    // 대각선 요소가 0인 경우
                    if (grid[i][j] == 0) {
                        return false;
                    }
                } else {
                    // 대각선이 아닌데 요소가 0이 아닌 경우
                    if (grid[i][j] != 0) {
                        return false;
                    }
                }
            }
        }

        // 문제가 없으면 true 반환
        return true;
    }
};

// int main() {
//     Solution solution;
//     int n;

//     cout << "행렬의 크기를 입력하세요: ";
//     cin >> n;

//     vector<vector<int>> grid(n, vector<int>(n));

//     cout << "행렬의 요소들을 입력하세요:\n";
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     if (solution.checkXMatrix(grid)) {
//         cout << "이 행렬은 'X' 행렬입니다." << endl;
//     } else {
//         cout << "이 행렬은 'X' 행렬이 아닙니다." << endl;
//     }

//     return 0;
// }
