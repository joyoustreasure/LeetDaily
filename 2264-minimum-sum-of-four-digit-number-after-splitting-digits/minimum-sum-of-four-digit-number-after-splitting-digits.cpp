#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 간단한 버블 정렬 함수 구현
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    int minimumSum(int num) {
        vector<int> a(4);
        // 주어진 숫자의 각 자릿수를 분리하여 벡터 a에 저장
        for(int i = 0; i < a.size(); i++) {
            a[i] = num % 10;
            num /= 10;
        }
        bubbleSort(a); // 정렬
        return (a[0] + a[1]) * 10 + a[2] + a[3];
    }
};

// int main() {
//     Solution solution;
    
//     int num = 2314;
//     int result = solution.minimumSum(num);
    
//     cout << "The minimum sum for " << num << " is: " << result << endl;

//     return 0;
// }
