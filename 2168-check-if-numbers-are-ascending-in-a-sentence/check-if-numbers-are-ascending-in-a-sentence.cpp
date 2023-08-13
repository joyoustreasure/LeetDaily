#include <iostream>
#include <vector>

class Solution {
public:
    bool areNumbersAscending(std::string s) {
        int n = s.size();           // 입력 문자열의 길이를 저장합니다.
        std::vector<int> nums;      // 숫자들을 저장할 벡터를 생성합니다.
        
        for (int i = 0; i < n; ++i) {
            if (isdigit(s[i])) {    // 현재 문자가 숫자인지 확인합니다.
                std::string temp;   // 숫자를 임시로 저장할 문자열을 생성합니다.
                while (i < n && isdigit(s[i])) {
                    temp += s[i++]; // 연속된 숫자들을 임시 문자열에 추가합니다.
                }
                nums.push_back(stoi(temp)); // 문자열을 정수로 변환하여 벡터에 저장합니다.
            }
        }
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] >= nums[i + 1]) {
                return false; // 숫자들을 순회하며 인접한 숫자가 내림차순인 경우 false를 반환합니다.
            }
        }
        
        return true; // 모든 숫자들이 오름차순이라면 true를 반환합니다.
    }
};
