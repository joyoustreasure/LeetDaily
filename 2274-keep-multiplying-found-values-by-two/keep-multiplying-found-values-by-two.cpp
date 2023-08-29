#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 주어진 벡터에서 original 값이 있으면 original 값을 2배로 만드는 함수
    // 이 과정을 original 값이 벡터에 없을 때까지 반복하고, 마지막으로 계산된 original 값을 반환
    int findFinalValue(vector<int>& nums, int original) {
        bool b = true;
        while(b) {
            int i = 0;
            for(i = 0; i < nums.size(); i++) {
                if(nums[i] == original) {
                    original *= 2; 
                    break;
                }
            }
            // original 값이 벡터에 없는 경우 반복 종료
            if(i == nums.size())
                b = false;
        }
        return original;
    }
};

// int main() {
//     Solution solution;
    
//     vector<int> nums = {1, 2, 4, 8, 16};
//     int original = 2;

//     int result = solution.findFinalValue(nums, original);
    
//     cout << "The final value is: " << result << endl;

//     return 0;
// }
