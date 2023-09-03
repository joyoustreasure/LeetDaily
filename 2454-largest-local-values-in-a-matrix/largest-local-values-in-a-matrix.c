#include <stdlib.h>

int maxInGrid(int i, int j, int** grid) {
    int max_val = grid[i-1][j-1];
    max_val = (max_val > grid[i-1][j]) ? max_val : grid[i-1][j];
    max_val = (max_val > grid[i-1][j+1]) ? max_val : grid[i-1][j+1];
    max_val = (max_val > grid[i][j-1]) ? max_val : grid[i][j-1];
    max_val = (max_val > grid[i][j]) ? max_val : grid[i][j];
    max_val = (max_val > grid[i][j+1]) ? max_val : grid[i][j+1];
    max_val = (max_val > grid[i+1][j-1]) ? max_val : grid[i+1][j-1];
    max_val = (max_val > grid[i+1][j]) ? max_val : grid[i+1][j];
    max_val = (max_val > grid[i+1][j+1]) ? max_val : grid[i+1][j+1];
    return max_val;
}

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {
    int n = gridSize;
    *returnSize = n - 2;
    
    int** res = (int**)malloc((*returnSize) * sizeof(int*));
    *returnColumnSizes = (int*)malloc((*returnSize) * sizeof(int));
    
    for(int i = 0; i < *returnSize; i++) {
        res[i] = (int*)malloc((n-2) * sizeof(int));
        (*returnColumnSizes)[i] = n - 2;
    }

    for(int i = 1; i <= n-2; i++) {
        for(int j = 1; j <= n-2; j++) {
            res[i-1][j-1] = maxInGrid(i, j, grid);
        }
    }
    
    return res;
}

// int main() {
//     int gridSize = 5;
//     int gridColSize[] = {5, 5, 5, 5, 5};
//     int* grid[] = {
//         (int[]) {1, 1, 1, 1, 1},
//         (int[]) {1, 1, 1, 1, 1},
//         (int[]) {1, 1, 2, 1, 1},
//         (int[]) {1, 1, 1, 1, 1},
//         (int[]) {1, 1, 1, 1, 1}
//     };

//     int returnSize;
//     int* returnColumnSizes;
//     int** result = largestLocal(grid, gridSize, gridColSize, &returnSize, &returnColumnSizes);

//     for(int i = 0; i < returnSize; i++) {
//         for(int j = 0; j < returnColumnSizes[i]; j++) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }

//     for(int i = 0; i < returnSize; i++) {
//         free(result[i]);
//     }
//     free(result);
//     free(returnColumnSizes);

//     return 0;
// }
