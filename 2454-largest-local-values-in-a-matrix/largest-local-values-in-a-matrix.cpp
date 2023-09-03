


//ver2 algorithm 사용
#include <iostream>
#include <vector>
#include <algorithm> // max 함수를 위해 필요합니다.

using namespace std;

class Solution 
{
public:
    // 3x3 부분 그리드의 최대 값을 찾는 함수입니다.
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int> (n-2));
        
        // 3x3 그리드의 중심을 기준으로 최대 값을 찾습니다.
        // 예: (1,1)에서 시작하면 (1,1),(1,2),(2,1),(2,2)는 각각 3x3 그리드의 중심이 됩니다.
        for(int i = 1; i <= n-2; i++)
        {
            for(int j = 1; j <= n-2; j++)
            {
                int maxi = 0;
                maxi = max({maxi, grid[i-1][j-1], grid[i-1][j], grid[i-1][j+1]});
                maxi = max({maxi, grid[i][j-1], grid[i][j], grid[i][j+1]});
                maxi = max({maxi, grid[i+1][j-1], grid[i+1][j], grid[i+1][j+1]});
                
                res[i-1][j-1] = maxi;
            }
        }
        return res;
    }
};

// int main() {
//     Solution sol;
//     vector<vector<int>> grid = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12},
//         {13, 14, 15, 16}
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
