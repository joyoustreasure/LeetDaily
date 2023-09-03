#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 수동으로 배열을 오름차순으로 정렬하는 함수
    void sortArray(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                }
            }
        }
    }

    int minimumOperations(vector<int>& nums) {
        // 배열을 오름차순으로 정렬
        sortArray(nums);
        int count = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) { // 첫 번째 양수를 찾음
                int x = nums[i];
                count++;

                // 해당 양수를 나머지 모든 원소에서 뺌
                for (int j = i; j < nums.size(); j++) {
                    nums[j] -= x;
                }
            }
        }
        return count;
    }
};

// int main() {
//     Solution solution;
//     vector<int> nums;
//     int n;

//     cout << "정수의 개수를 입력하세요: ";
//     cin >> n;

//     cout << "정수들을 입력하세요: ";
//     for (int i = 0; i < n; i++) {
//         int num;
//         cin >> num;
//         nums.push_back(num);
//     }

//     int result = solution.minimumOperations(nums);
//     cout << "최소 연산 횟수: " << result << endl;

//     return 0;
// }
