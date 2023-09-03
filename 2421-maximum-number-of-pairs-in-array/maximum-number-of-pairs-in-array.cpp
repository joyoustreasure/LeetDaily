#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int, int> mp;
        // 각 숫자의 출현 횟수를 맵에 저장
        for (int i : nums) mp[i]++;
        
        int count = 0, count1 = 0;
        for (auto it : mp) {
            // 페어를 만들 수 있는 횟수 계산
            count += (it.second / 2);
            // 페어를 만들 수 없는 남은 숫자의 개수 계산
            count1 += (it.second % 2);
        }
        return {count, count1};
    }
};

// int main() {
//     Solution solution;
//     vector<int> nums;

//     int n;
//     cout << "숫자 목록의 크기를 입력하세요: ";
//     cin >> n;

//     cout << "숫자들을 입력하세요: ";
//     for (int i = 0; i < n; i++) {
//         int num;
//         cin >> num;
//         nums.push_back(num);
//     }

//     vector<int> result = solution.numberOfPairs(nums);
//     cout << "만들 수 있는 페어의 개수: " << result[0] << endl;
//     cout << "페어를 만들 수 없는 남은 숫자의 개수: " << result[1] << endl;

//     return 0;
// }
