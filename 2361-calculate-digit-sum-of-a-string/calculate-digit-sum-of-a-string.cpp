#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
    string ans;
    while (true) {
        if (s.length() <= k) return s;

        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i != 0 && i % k == 0) {
                ans += to_string(sum);
                sum = 0;
            }
            sum += (s[i] - '0');
        } // end of for

        ans += to_string(sum);
        s = ans;
        ans = "";
    } // end of while

    // 이 부분은 실행되지 않습니다. 하지만 반환 타입을 만족시키기 위해 추가합니다.
    return ans;
}
};



// int main() {
//     string s = "123456789";
//     int k = 3;
//     cout << digitSum(s, k) << endl; // Expected output: "152491223"
//     return 0;
// }
