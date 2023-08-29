#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void bubbleSort(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < n-i-1; j++) {
                if (A[j] > A[j+1]) {
                    swap(A[j], A[j+1]);
                }
            }
        }
    }

    int minimumCost(vector<int>& A) {
        // 벡터 A를 오름차순으로 정렬
        bubbleSort(A);

        int res = 0, n = A.size();
        
        // 벡터의 모든 요소를 순회
        for (int i = 0; i < A.size(); ++i) {
            // i와 n의 나머지가 다르면 해당 요소를 결과에 추가
            if (i % 3 != n % 3) {
                res += A[i];
            }
        }
        
        return res;
    }
};

// int main() {
//     Solution solution;
    
//     vector<int> nums = {3, 6, 2, 8, 7, 5};
    
//     int result = solution.minimumCost(nums);
    
//     cout << "The minimum cost is: " << result << endl;

//     return 0;
// }
