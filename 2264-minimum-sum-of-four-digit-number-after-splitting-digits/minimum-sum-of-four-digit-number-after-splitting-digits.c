#include <stdio.h>

// 간단한 버블 정렬 함수 구현
void bubbleSort(int arr[], int n) {
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

int minimumSum(int num) {
    int a[4];
    
    // 주어진 숫자의 각 자릿수를 분리하여 배열 a에 저장
    for (int i = 0; i < 4; i++) {
        a[i] = num % 10;
        num /= 10;
    }
    
    bubbleSort(a, 4); // 정렬
    
    return (a[0] + a[1]) * 10 + a[2] + a[3];
}

// int main() {
//     int num = 2314;
//     int result = minimumSum(num);
    
//     printf("The minimum sum for %d is: %d\n", num, result);

//     return 0;
// }
