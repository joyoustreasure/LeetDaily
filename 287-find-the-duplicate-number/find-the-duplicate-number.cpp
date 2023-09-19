class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::vector<int> copy = nums;
        std::sort(copy.begin(), copy.end(), std::greater<int>());
        for (int i=0;i<copy.size()-1;i++){
            if(copy[i]==copy[i+1]){return copy[i];}
        }
        return -1;
}
};