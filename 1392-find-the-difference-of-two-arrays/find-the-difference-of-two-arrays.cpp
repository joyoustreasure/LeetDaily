#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 두 벡터(nums1, nums2)에서 서로 다른 요소를 찾아서 반환하는 함수
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // nums1의 요소를 저장할 집합
        unordered_set<int> set1(nums1.begin(), nums1.end());
        // nums2의 요소를 저장할 집합
        unordered_set<int> set2(nums2.begin(), nums2.end());

        // nums1에만 있는 요소를 저장할 벡터
        vector<int> distinct_nums1;
        // nums2에만 있는 요소를 저장할 벡터
        vector<int> distinct_nums2;

        // nums1에만 있는 요소 찾기
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        // nums2에만 있는 요소 찾기
        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        // 결과 반환
        return {distinct_nums1, distinct_nums2};
    }
};

// int main() {
//     Solution sol;
//     vector<int> nums1 = {1, 2, 3, 4};
//     vector<int> nums2 = {3, 4, 5, 6};

//     vector<vector<int>> result = sol.findDifference(nums1, nums2);

//     cout << "nums1에서만 있는 요소: ";
//     for (int num : result[0]) {
//         cout << num << " ";
//     }
//     cout << endl;

//     cout << "nums2에서만 있는 요소: ";
//     for (int num : result[1]) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }
