#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool check(string s) {
        int l = 0, h = s.size() - 1;
        while(l < h) {
            if(s[l++] != s[h--])
                return false;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) {
        int i;
        for(i = 0; i < words.size(); i++) {
            if(check(words[i]))
                return words[i];
        }
        return "";
    }
};

// int main() {
//     Solution sol;
//     int n;
//     vector<string> words;

//     cout << "단어의 개수를 입력하세요: ";
//     cin >> n;

//     cout << "단어들을 입력하세요:" << endl;
//     for(int i = 0; i < n; i++) {
//         string word;
//         cin >> word;
//         words.push_back(word);
//     }

//     string result = sol.firstPalindrome(words);
//     if(result != "") {
//         cout << "첫 번째 회문: " << result << endl;
//     } else {
//         cout << "회문이 없습니다." << endl;
//     }

//     return 0;
// }
