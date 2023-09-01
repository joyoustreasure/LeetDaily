#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> res;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
        if (nums[i] == key) {
            for (j = max(j, i - k); j <= i + k && j < nums.size(); ++j) {
                res.push_back(j);
            }
        }
    }
    return res;
}
};



// int main() {
//     int n, key, k;

//     // 배열의 크기 입력 받기
//     cout << "배열의 크기를 입력하세요: ";
//     cin >> n;

//     vector<int> nums(n);

//     // 배열의 원소 입력 받기
//     cout << "배열의 원소를 입력하세요: ";
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }

//     // key와 k 입력 받기
//     cout << "key 값을 입력하세요: ";
//     cin >> key;
//     cout << "k 값을 입력하세요: ";
//     cin >> k;

//     // 결과 계산
//     vector<int> result = findKDistantIndices(nums, key, k);

//     // 결과 출력
//     cout << "k 거리 내의 인덱스: ";
//     for (int idx : result) {
//         cout << idx << " ";
//     }

//     return 0;
// }
