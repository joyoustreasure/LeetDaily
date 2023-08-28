class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // 변수 선언
        int n = nums.size(), i = 0, t = k;
        // 결과를 저장할 벡터
        vector<int> ans;

        // 처음 k개의 원소를 ans에 추가
        while(t > 0) {
            ans.push_back(nums[i]);
            i++;
            t--;
        }

        // 나머지 배열을 순회
        for(int j = i; j < n; j++) {
            // ans 배열에서의 최솟값을 직접 찾음
            int mini = 0;
            for(int m = 1; m < ans.size(); m++) {
                if(ans[m] < ans[mini]) {
                    mini = m;
                }
            }

            // 현재 원소와 비교하여 현재 원소가 크면 최솟값을 제거하고 현재 원소를 추가
            if(ans[mini] < nums[j]) {
                ans.erase(ans.begin() + mini);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
 };

// int main() {
//     Solution sol;
//     vector<int> nums;
//     int n, k, val;

//     // 배열의 크기와 k 값을 입력
//     cout << "배열의 크기를 입력하세요: ";
//     cin >> n;
//     cout << "부분 수열의 길이 k를 입력하세요: ";
//     cin >> k;

//     // 배열의 원소들을 입력
//     cout << "배열의 원소들을 입력하세요: ";
//     for(int i = 0; i < n; i++) {
//         cin >> val;
//         nums.push_back(val);
//     }

//     // maxSubsequence 함수를 호출하여 결과를 출력
//     vector<int> result = sol.maxSubsequence(nums, k);
//     cout << "합이 최대가 되는 길이 " << k << "인 부분 수열: ";
//     for(int num : result) {
//         cout << num << " ";
//     }
//     cout << endl;

//     return 0;
// }
