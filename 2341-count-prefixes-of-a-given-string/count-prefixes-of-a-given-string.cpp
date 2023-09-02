#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 각 words[i]에 대해 반복하고, s에서 words[i]의 크기와 같은 부분 문자열 str을 가져옵니다.
    // str와 words[i]가 같은 경우 count를 1 증가시킵니다.
    int countPrefixes(vector<string>& words, string s) 
    {
        int count=0;
        for(auto it: words)
        {
            string str = s.substr(0, it.size());
            if(str == it) count++;            
        }
        return count;        
    }
};

// int main() {
//     Solution solution;
//     vector<string> words = {"hel", "world", "he"};
//     string s = "hello";
    
//     cout << "접두사의 수: " << solution.countPrefixes(words, s) << endl;

//     return 0;
// }
