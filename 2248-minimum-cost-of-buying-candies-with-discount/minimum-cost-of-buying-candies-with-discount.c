#include <stdio.h>

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int minimumCost(int* cost, int costSize) {
    // 배열 cost를 오름차순으로 정렬
    bubbleSort(cost, costSize);

    int res = 0;
    
    // 배열의 모든 요소를 순회
    for (int i = 0; i < costSize; ++i) {
        // i와 costSize의 나머지가 다르면 해당 요소를 결과에 추가
        if (i % 3 != costSize % 3) {
            res += cost[i];
        }
    }
    
    return res;
}

// int main() {
//     int cost[] = {3, 6, 2, 8, 7, 5};
//     int costSize = sizeof(cost) / sizeof(cost[0]);
    
//     int result = minimumCost(cost, costSize);
    
//     printf("The minimum cost is: %d\n", result);

//     return 0;
// }
