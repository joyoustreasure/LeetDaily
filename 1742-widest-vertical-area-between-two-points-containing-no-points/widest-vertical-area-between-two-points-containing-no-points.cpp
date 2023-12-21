class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0]<b[0];
        });
    
    int cur_max=0;
    
    for (int i=0;i<points.size()-1;i++){
        int cur_val = points[i+1][0]-points[i][0];
        cur_max = std::max(cur_val, cur_max);
    }
    return cur_max;
    }

};