#include <stdio.h>
#include <stdbool.h>

bool checkXMatrix(int** grid, int gridSize, int* gridColSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            // 대각선인지 확인
            if (j == i || j == gridSize-i-1) {
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

// int main() {
//     int n;

//     printf("행렬의 크기를 입력하세요: ");
//     scanf("%d", &n);

//     int** grid = (int**)malloc(n * sizeof(int*));
//     int* gridColSize = (int*)malloc(n * sizeof(int));

//     for (int i = 0; i < n; i++) {
//         grid[i] = (int*)malloc(n * sizeof(int));
//         gridColSize[i] = n;
//         for (int j = 0; j < n; j++) {
//             scanf("%d", &grid[i][j]);
//         }
//     }

//     if (checkXMatrix(grid, n, gridColSize)) {
//         printf("이 행렬은 'X' 행렬입니다.\n");
//     } else {
//         printf("이 행렬은 'X' 행렬이 아닙니다.\n");
//     }

//     // 메모리 해제
//     for (int i = 0; i < n; i++) {
//         free(grid[i]);
//     }
//     free(grid);
//     free(gridColSize);

//     return 0;
// }
