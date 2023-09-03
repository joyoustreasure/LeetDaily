#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& r, vector<char>& s) {
        // 각 무늬의 개수를 저장할 벡터 초기화
        vector<int> v(26, 0);
        // 카드 숫자의 빈도를 저장할 맵 초기화
        unordered_map<int, int> mp;
        
        // 무늬 빈도 계산
        for (char c : s) {
            v[c - 'a']++;
        }

        // 숫자 빈도 계산
        for (int x : r) {
            mp[x]++;
        }

        // 5장 이상의 동일한 무늬의 카드가 있는지 확인
        for (int x : v) {
            if (x >= 5) return "Flush";
        }

        bool ans = false;
        for (auto it : mp) {
            // 3장의 동일한 숫자의 카드가 있는지 확인
            if (it.second >= 3) return "Three of a Kind";
            // 2장의 동일한 숫자의 카드가 있는지 확인
            if (it.second >= 2) ans = true;
        }
        
        if (ans) return "Pair";
        return "High Card";
    }
};

// int main() {
//     Solution solution;
//     vector<int> r = {2, 3, 4, 5, 6};
//     vector<char> s = {'h', 'h', 'h', 'h', 'h'};

//     string result = solution.bestHand(r, s);
//     cout << "최고의 포커 핸드: " << result << endl;

//     return 0;
// }
