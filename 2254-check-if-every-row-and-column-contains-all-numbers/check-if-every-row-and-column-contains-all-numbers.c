#include <stdio.h>
#include <stdbool.h>

bool checkValid(int** matrix, int matrixSize, int* matrixColSize) {
    // 각 행과 열의 숫자를 저장하기 위한 배열
    int row[matrixSize + 1];
    int col[matrixSize + 1];

    // 모든 행과 열을 순회
    for (int i = 0; i < matrixSize; i++) {
        // 배열 초기화
        for (int k = 0; k <= matrixSize; k++) {
            row[k] = 0;
            col[k] = 0;
        }

        // i번째 행의 숫자와 i번째 열의 숫자를 배열에 추가
        for (int j = 0; j < matrixSize; j++) {
            row[matrix[i][j]]++;
            col[matrix[j][i]]++;
        }

        // 배열의 각 요소가 1이 아니면 중복된 숫자가 있음을 의미
        for (int k = 1; k <= matrixSize; k++) {
            if (row[k] != 1 || col[k] != 1) return false;
        }
    }

    // 모든 행과 열에 중복된 숫자가 없다면 true 반환
    return true;
}

// int main() {
//     int n = 3;
//     int matrixColSize[n];
//     for (int i = 0; i < n; i++) {
//         matrixColSize[i] = n;
//     }

//     int* matrix[n];
//     int row1[] = {1, 2, 3};
//     int row2[] = {2, 3, 1};
//     int row3[] = {3, 1, 2};
//     matrix[0] = row1;
//     matrix[1] = row2;
//     matrix[2] = row3;

//     if (checkValid(matrix, n, matrixColSize)) {
//         printf("행렬이 유효합니다.\n");
//     } else {
//         printf("행렬이 유효하지 않습니다.\n");
//     }

//     return 0;
// }
