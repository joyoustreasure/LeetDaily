#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // 두 항목 목록을 병합하여 유사한 항목을 합친 결과를 반환하는 함수
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> output;
        map<int, int> itemMap; // 각 ID에 대한 항목 값의 누적을 저장하기 위한 맵
        for(auto item : items1){
            itemMap[item[0]] += item[1];
        }
        for(auto item : items2){
            itemMap[item[0]] += item[1];
        }
        for(auto item : itemMap){
            output.push_back({item.first, item.second});
        }
        return output;
    }
};

// int main() {
//     Solution solution;
//     // 테스트 케이스
//     vector<vector<int>> items1 = {{1, 5}, {2, 3}, {3, 4}};
//     vector<vector<int>> items2 = {{2, 4}, {3, 5}, {4, 6}};
//     vector<vector<int>> merged = solution.mergeSimilarItems(items1, items2);

//     for(auto item : merged) {
//         cout << "ID: " << item[0] << ", Value: " << item[1] << endl;
//     }

//     return 0;
// }
