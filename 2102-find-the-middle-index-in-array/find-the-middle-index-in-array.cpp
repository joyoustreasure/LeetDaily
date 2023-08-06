class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int l_sum = 0, r_sum = 0;
        for (int num : nums) {
            r_sum += num;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (l_sum == r_sum - nums[i]) {
                return i;
            }

            l_sum += nums[i];
            r_sum -= nums[i];
        }

        return -1;
    }
};