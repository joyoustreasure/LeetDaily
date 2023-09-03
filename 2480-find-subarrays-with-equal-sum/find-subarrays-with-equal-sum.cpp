#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(nums[i], nums[min_idx]);
        }
    }
}

bool findSubarrays(vector<int>& nums) {
    int n = nums.size();

    if (nums.size() <= 2)
        return false;

    for (int i = 1; i < n; i++) {
        int sum = nums[i-1] + nums[i];
        nums[i-1] = sum;
    }
    nums.pop_back();
    selectionSort(nums); // 직접 구현한 선택 정렬 사용

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] == nums[i])
            return true;
    }
    return false;
}
};





// int main() {
//     vector<int> nums = {1, 2, 3, 5, 3, 2};
//     if (findSubarrays(nums)) {
//         cout << "True: There are repeated sums in consecutive subarrays." << endl;
//     } else {
//         cout << "False: No repeated sums in consecutive subarrays." << endl;
//     }
//     return 0;
// }
