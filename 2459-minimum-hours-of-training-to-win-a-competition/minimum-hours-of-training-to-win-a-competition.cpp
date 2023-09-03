#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 주어진 에너지와 경험치를 보완하는 데 필요한 최소 시간을 계산하는 함수입니다.
    int minNumberOfHours(int ie, int ig, vector<int>& energy, vector<int>& experience) {
        int hours = 0;
        for (int i = 0; i < energy.size(); i++) {
            // 에너지가 부족하면 시간을 추가하고 에너지를 보충합니다.
            if (energy[i] >= ie) {
                hours += energy[i] - ie + 1;
                ie += energy[i] - ie + 1;
            }
            // 경험치가 부족하면 시간을 추가하고 경험치를 보충합니다.
            if (experience[i] >= ig) {
                hours += experience[i] - ig + 1;
                ig += experience[i] - ig + 1;
            }
            // 마지막으로 경험치를 더하고 에너지를 감소시킵니다.
            ie -= energy[i];
            ig += experience[i];
        }
        return hours;
    }
};

// int main() {
//     Solution sol;
//     vector<int> energy = {1, 2, 3};
//     vector<int> experience = {2, 1, 3};
//     int ie = 1;
//     int ig = 2;
//     cout << sol.minNumberOfHours(ie, ig, energy, experience) << endl;  // 예상 출력: 5
//     return 0;
// }
