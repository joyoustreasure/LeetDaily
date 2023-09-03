#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    // 주어진 문자열에서 길이 k의 부분 문자열 중에서 'W' 문자의 최소 개수를 찾는 함수입니다.
    int minimumRecolors(string blocks, int k) {
        int back = 0, front = 0, count_w = 0, ans = INT_MAX;
        
        // 슬라이딩 윈도우 기법을 사용합니다.
        while(front < blocks.size()){
            if(blocks[front] == 'W'){ 
                count_w++; 
            }
            
            // 현재 윈도우의 크기가 k와 같으면
            if(front - back + 1 == k){
                ans = min(ans, count_w);
                if(blocks[back] == 'W') count_w--;
                back++;
            }
            front++;
        }
        return ans;
    }
};

// int main() {
//     Solution sol;
    
//     string blocks = "BWBWWB";
//     int k = 3;
//     cout << sol.minimumRecolors(blocks, k) << endl;  // 예상 출력: 2

//     return 0;
// }
