class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int dup=-1;
        int missing=-1;
        vector<int>v(n+1,0);
        for(int i=0; i<n;i++){
            v[nums[i]]++;
        }
        for(int j=1;j<n+1;j++){
            if(v[j]==0) missing=j; 
            else if(v[j]==2) dup=j;
        }
        return {dup,missing};
    }
};