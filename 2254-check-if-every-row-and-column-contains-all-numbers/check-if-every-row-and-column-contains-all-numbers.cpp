#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    // 2D 행렬(정사각형)이 각 행과 열에 중복된 숫자가 없는지 확인하는 함수
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();  // 행렬의 크기(행 또는 열의 개수)

        // 모든 행과 열을 순회
        for (int i = 0; i < n; i++) {
            set<int> row, col;  // 각 행과 열의 숫자를 저장하기 위한 집합

            // i번째 행의 숫자와 i번째 열의 숫자를 집합에 추가
            for (int j = 0; j < n; j++) {
                row.insert(matrix[i][j]);
                col.insert(matrix[j][i]);
            }

            // 집합의 크기가 n과 다르면 중복된 숫자가 있음을 의미
            if (row.size() != n || col.size() != n) return false;
        }

        // 모든 행과 열에 중복된 숫자가 없다면 true 반환
        return true;
    }
};

// int main() {
//     Solution solution;
//     vector<vector<int>> matrix = {
//         {1, 2, 3},
//         {2, 3, 1},
//         {3, 1, 2}
//     };

//     if (solution.checkValid(matrix)) {
//         cout << "행렬이 유효합니다." << endl;
//     } else {
//         cout << "행렬이 유효하지 않습니다." << endl;
//     }

//     return 0;
// }
