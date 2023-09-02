#include <iostream>

using namespace std;

class Solution {
public:
    // 두 정수 start와 goal의 비트를 비교하여 몇 번의 비트 플립이 필요한지 계산하는 함수
    int minBitFlips(int start, int goal) 
    {   
        int flips = 0;
		
		// start와 goal 둘 다 0이 될 때까지 반복합니다.
        while(start || goal)
        {
			// 현재 비트가 다르다면 비트 플립이 필요합니다.
            if(start % 2 != goal % 2)
                flips++;
            
            // 다음 비트로 이동합니다.
            start /= 2;
            goal /= 2;
        }
        return flips;
    }
};

// int main() {
//     Solution sol;
//     int start = 10;
//     int goal = 3;
//     int result = sol.minBitFlips(start, goal);
//     cout << "최소 비트 플립 횟수: " << result << endl;
//     return 0;
// }
