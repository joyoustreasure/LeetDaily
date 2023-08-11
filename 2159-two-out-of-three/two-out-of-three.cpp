class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        // 세 개의 입력 벡터에서 중복되지 않는 값을 저장하는 unordered_set 선언
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        unordered_set<int> set3(nums3.begin(), nums3.end());
        
        // 결과를 저장할 unordered_set 선언
        unordered_set<int> result;
        
        // set1을 순회하면서 set2나 set3에 이미 있는 값인지 확인하고 결과에 추가
        for (int num : set1) {
            if (set2.count(num) || set3.count(num)) {
                result.insert(num);
            }
        }
        
        // set2를 순회하면서 set1이나 set3에 이미 있는 값인지 확인하고 결과에 추가
        for (int num : set2) {
            if (set1.count(num) || set3.count(num)) {
                result.insert(num);
            }
        }
        
        // set3를 순회하면서 set1이나 set2에 이미 있는 값인지 확인하고 결과에 추가
        for (int num : set3) {
            if (set1.count(num) || set2.count(num)) {
                result.insert(num);
            }
        }
        
        // 결과 unordered_set을 vector<int>로 변환하여 반환
        return vector<int>(result.begin(), result.end());
    }
};
