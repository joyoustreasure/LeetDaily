#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 간단한 삽입 정렬을 사용하여 벡터를 정렬합니다.
    void mySort(vector<int>& v) {
        for (int i = 1; i < v.size(); i++) {
            int key = v[i];
            int j = i - 1;
            while (j >= 0 && v[j] > key) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = key;
        }
    }

    // upper_bound 함수를 직접 구현합니다.
    int myUpperBound(const vector<int>& v, int x) {
        int l = 0, r = v.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (v[mid] <= x)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }

    vector<int> answerQueries(vector<int>& v, vector<int>& q) {
        mySort(v); // 정렬 함수를 직접 호출

        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }

        vector<int> ans;
        for (int x : q) {
            int idx = myUpperBound(v, x); // upper_bound 함수를 직접 호출
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

//     for (int i : result) {
//         cout << i << " ";
//     }
//     // 예상 출력: 2 4 5
//     return 0;
// }
