#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 주어진 배열에서 key 다음에 가장 자주 나오는 숫자를 반환하는 함수
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> umap;  // 각 숫자의 빈도를 저장하는 해시맵
        int count = 0;  // 현재까지 확인한 최대 빈도
        int ans = nums[0];  // 정답으로 저장될 숫자
        
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == key) {
                umap[nums[i+1]]++;  // key 다음의 숫자의 빈도 증가
                
                // 해당 숫자의 빈도가 현재 최대 빈도보다 크면 정답 갱신
                if(umap[nums[i+1]] > count) {
                    count = umap[nums[i+1]];
                    ans = nums[i+1];
                }
            }
        }
        return ans;
    }
};

// int main() {
//     Solution solution;
//     vector<int> nums = {1, 2, 1, 3, 2, 1, 3, 2};
//     int key = 1;

//     // 결과를 계산하고 출력
//     int result = solution.mostFrequent(nums, key);
//     cout << key << " 다음에 가장 자주 나오는 숫자: " << result << endl;

//     return 0;
// }
