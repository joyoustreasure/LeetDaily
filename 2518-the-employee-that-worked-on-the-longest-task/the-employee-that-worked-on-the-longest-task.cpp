#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int last = 0, emp = 0, larg = 0, period;
        for(vector<int>& log: logs) {
            period = log[1] - last;
            if(larg == period)
                emp = min(emp, log[0]);
            else if(larg < period) {
                larg = period;
                emp = log[0];
            }
            last = log[1];
        }
        return emp;
    }
};

// int main() {
//     Solution sol;
//     int n;
    
//     cout << "사원 수를 입력하세요: ";
//     cin >> n;
    
//     vector<vector<int>> logs(n, vector<int>(2));
//     for (int i = 0; i < n; i++) {
//         cout << i + 1 << "번째 사원의 출근 및 퇴근 시간을 입력하세요: ";
//         cin >> logs[i][0] >> logs[i][1];
//     }
    
//     int result = sol.hardestWorker(n, logs);
//     cout << "가장 열심히 일한 사원 번호: " << result << endl;
    
//     return 0;
// }
