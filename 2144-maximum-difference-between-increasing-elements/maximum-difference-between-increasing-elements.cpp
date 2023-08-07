class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int cur = -1;
        for (int i=0;i<nums.size();i++){
            for (int j=i+1;j<nums.size();j++){
                if (nums[j]-nums[i]>cur && nums[i]!=nums[j]){
                    cur = nums[j]-nums[i];
                }
            }
        }
        return cur;
    }
};