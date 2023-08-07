#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 2D 배열을 구성하는 함수입니다.
 * 
 * @param original 원본 1차원 배열
 * @param originalSize 원본 배열의 크기
 * @param m 원하는 행 수
 * @param n 원하는 열 수
 * @param returnSize 반환할 행 수
 * @param returnColumnSizes 열 크기를 저장할 배열의 포인터
 * @return int** 생성된 2차원 배열의 포인터
 * 
 * @note 호출자는 반환된 배열 및 returnColumnSizes 배열을 free() 함수로 해제해야 합니다.
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    int** ans = NULL;
    *returnSize = m;

    // 전체 원소 수가 원하는 2D 배열 크기와 일치하는지 확인
    if (originalSize != m * n) {
        *returnSize = 0; // 크기가 유효하지 않으면 반환 크기를 0으로 설정
        return ans;      // NULL 포인터 반환
    }

    // 배열의 배열(2D 배열)과 열 크기 배열에 메모리 할당
    ans = (int**)malloc(m * sizeof(int*));
    *returnColumnSizes = (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; ++i) {
        // 각 행(하위 배열)에 메모리 할당 및 열 크기 설정
        ans[i] = (int*)malloc(n * sizeof(int));
        (*returnColumnSizes)[i] = n;

        // 원본 배열의 원소를 행(하위 배열)에 복사
        for (int j = 0; j < n; ++j) {
            ans[i][j] = original[i * n + j];
        }
    }

    return ans; // 생성된 2D 배열 반환
}
