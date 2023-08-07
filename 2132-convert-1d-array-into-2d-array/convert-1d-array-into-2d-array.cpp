#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {
        std::vector<std::vector<int>> ans;

        if (original.size() != m * n) {
            return ans; // Return an empty vector since the size is invalid
        }

        for (int i = 0; i < original.size(); i += n) {
            std::vector<int> row(original.begin() + i, original.begin() + i + n);
            ans.push_back(row);
        }

        return ans;
    }
};