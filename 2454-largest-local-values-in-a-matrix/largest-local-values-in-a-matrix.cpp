#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    // 주어진 숫자들 중에서 최대값을 반환하는 함수
    int maxInGrid(int i, int j, vector<vector<int>>& grid) {
        int max_val = grid[i-1][j-1];
        max_val = max(max_val, grid[i-1][j]);
        max_val = max(max_val, grid[i-1][j+1]);
        max_val = max(max_val, grid[i][j-1]);
        max_val = max(max_val, grid[i][j]);
        max_val = max(max_val, grid[i][j+1]);
        max_val = max(max_val, grid[i+1][j-1]);
        max_val = max(max_val, grid[i+1][j]);
        max_val = max(max_val, grid[i+1][j+1]);
        return max_val;
    }

    // 3x3 부분 그리드의 최대 값을 찾는 함수입니다.
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int> (n-2));
        
        // 3x3 그리드의 모든 값을 고려하여 최대 값을 찾습니다.
        for(int i = 1; i <= n-2; i++)
        {
            for(int j = 1; j <= n-2; j++)
            {
                res[i-1][j-1] = maxInGrid(i, j, grid);
            }
        }
        return res;
    }
};

// int main() {
//     Solution sol;
//     vector<vector<int>> grid = {
//         {1, 1, 1, 1, 1},
//         {1, 1, 1, 1, 1},
//         {1, 1, 2, 1, 1},
//         {1, 1, 1, 1, 1},
//         {1, 1, 1, 1, 1}
//     };

//     vector<vector<int>> result = sol.largestLocal(grid);
//     for (int i = 0; i < result.size(); i++) {
//         for (int j = 0; j < result[i].size(); j++) {
//             cout << result[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
