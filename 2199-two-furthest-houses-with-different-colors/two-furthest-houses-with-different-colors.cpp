#include <vector>

class Solution {
public:

int maxDistance(std::vector<int>& colors) {
    const int MAX_COLORS = 1001;
    std::vector<int> first(MAX_COLORS, -1);
    std::vector<int> last(MAX_COLORS, -1);

    // 각 색상의 첫 등장 위치와 마지막 등장 위치를 기록합니다.
    for (int i = 0; i < colors.size(); i++) {
        if (first[colors[i]] == -1) {
            first[colors[i]] = i;
        }
        last[colors[i]] = i;
    }

    int maxDist = 0;
    for (int i = 0; i < MAX_COLORS; i++) {
        for (int j = i + 1; j < MAX_COLORS; j++) {
            if (first[i] != -1 && first[j] != -1) {
                int dist1 = last[i] - first[j];
                int dist2 = last[j] - first[i];
                int currentMax = (dist1 > dist2) ? dist1 : dist2;
                if (currentMax > maxDist) {
                    maxDist = currentMax;
                }
            }
        }
    }

    return maxDist;
}

};

