#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 주어진 배열과 차이값을 사용하여 산술적인 삼중 숫자 조합의 개수를 반환하는 함수
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;

        // 배열 내의 모든 원소 조합에 대해 산술적인 조합이 있는지 확인
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                for(int k = j + 1; k < nums.size(); k++) {
                    if((nums[j] - nums[i]) == diff && (nums[k] - nums[j]) == diff) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

// int main() {
//     Solution sol;
//     vector<int> nums = {1, 3, 5, 7, 9, 11};
//     int diff = 2;

//     int result = sol.arithmeticTriplets(nums, diff);
//     cout << "산술적인 삼중 숫자 조합의 수: " << result << endl;

//     return 0;
// }
