#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        // 배열을 정렬
        sort(nums.begin(), nums.end());
        int i = 0;
        // 모든 요소를 검사
        while(i < n - 1){
            // 연속된 두 요소가 같지 않으면 false 반환
            if (nums[i] != nums[i+1]) return false;
            i = i+2;
        }
        // 모든 요소가 짝을 이룰 경우 true 반환
        return true;
    }
};

// int main() {
//     Solution sol;
//     vector<int> nums = {1, 2, 3, 1, 2, 3};
//     if (sol.divideArray(nums)) {
//         cout << "Array can be divided into pairs with the same elements." << endl;
//     } else {
//         cout << "Array cannot be divided into pairs with the same elements." << endl;
//     }
//     return 0;
// }
