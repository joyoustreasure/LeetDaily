#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 주어진 값들의 누적 합에 대해 각 질의를 어디에서 찾을 수 있는지 알려주는 함수입니다.
    vector<int> answerQueries(vector<int>& v, vector<int>& q) {
        // 먼저 v 벡터를 정렬합니다.
        sort(v.begin(), v.end());
        
        // v의 각 요소에 대해 누적 합을 계산합니다.
        for(int i=1; i<v.size(); i++) {
            v[i] += v[i-1];
        }
        
        vector<int> ans;
        // 각 질의에 대해 이진 검색을 사용하여 해당 값을 초과하는 첫 번째 위치를 찾습니다.
        for(int x: q) {
            int idx = upper_bound(v.begin(), v.end(), x) - v.begin();
            ans.push_back(idx);
        }
        
        return ans;
    }
};

// int main() {
//     Solution sol;
//     vector<int> v = {1, 2, 3, 4, 5};
//     vector<int> q = {5, 10, 15};

//     vector<int> result = sol.answerQueries(v, q);

//     for(int i : result) {
//         cout << i << " ";
//     }
//     // 예상 출력: 2 4 5
//     return 0;
// }
