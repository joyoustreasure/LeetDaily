#include <iostream>
#include <string>
#include <unordered_map> // unordered_map을 사용하기 위한 헤더
using namespace std;

class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char,int> mp;
        for(int i=0;i<num.length();i++)
        {
             mp[num[i]]++;
        }
        for(auto ele: mp)
        {
            
            if(ele.second!=num[ele.first-'0']-'0')
                return false;
        }
        return true;
        
    }
};


// int main() {
//     Solution solution;
//     string nums = "1210";

//     bool result = solution.digitCount(nums);
//     if(result) {
//         cout << "The number string " << nums << " satisfies the condition." << endl;
//     } else {
//         cout << "The number string " << nums << " does not satisfy the condition." << endl;
//     }

//     return 0;
// }
