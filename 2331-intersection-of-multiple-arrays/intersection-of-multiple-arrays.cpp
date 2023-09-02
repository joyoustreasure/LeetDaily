class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> map;
        for(const auto &arr: nums) {
            for(const auto &num: arr) {
                map[num]++;
            }
        }
        int n = nums.size();
        vector<int> res;
        for(const auto &it: map) {
            if(it.second == n) {
                res.push_back(it.first);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};