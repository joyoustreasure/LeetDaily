#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    // 주어진 단어에서 모든 문자의 빈도수가 같은지 검사하는 함수
    bool equalFrequency(string word) 
    {
        vector<int> mp(26, 0); // 각 알파벳의 빈도수를 저장하기 위한 벡터
        
        // 각 문자의 빈도수를 계산합니다.
        for(auto it:word)
            mp[it-'a']++;

        for(int i=0; i<26; i++) 
        {
            if(mp[i]==0) continue;  // 해당 문자가 없으면 다음 문자로 넘어갑니다.
            
            // 문자의 빈도수를 하나 줄입니다.
            mp[i]--;
            
            int fl=0, cnt=0, fl2=0; 
            for(int i=0; i<26; i++) 
            {
                if(mp[i]==0) continue; // 해당 문자가 없으면 다음 문자로 넘어갑니다.
                
                if(fl==0)  // 첫 번째 문자의 빈도수를 저장합니다.
                {
                    cnt = mp[i];
                    fl=1;
                }
                
                // 다른 문자의 빈도수와 같지 않으면 fl2를 1로 설정합니다.
                if(mp[i]!=cnt) 
                {
                    fl2=1; 
                    break;
                }
            }
            // fl2가 0이면 모든 문자의 빈도수가 같습니다.
            if(fl2==0) return true; 
            
            // 문자의 빈도수를 복원합니다.
            mp[i]++; 
        }
        return false;
    }
};

// int main() {
//     Solution sol;
//     string word;

//     cout << "단어를 입력하세요: ";
//     cin >> word;

//     if (sol.equalFrequency(word)) {
//         cout << "모든 문자의 빈도수가 같습니다." << endl;
//     } else {
//         cout << "모든 문자의 빈도수가 같지 않습니다." << endl;
//     }

//     return 0;
// }
