#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    // 문자열의 문자들을 정렬하는 함수
    string sortString(const string& s) {
        int frequency[26] = {0};
        for(char c : s) {
            frequency[c - 'a']++;
        }
        
        string sorted = "";
        for(int i = 0; i < 26; i++) {
            sorted += string(frequency[i], 'a' + i);
        }
        
        return sorted;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1; i < words.size(); i++) {
            string x = sortString(words[i]);
            string y = sortString(words[i-1]);
            
            if(x == y) {
                words.erase(words.begin() + i);
                i--;
            }
        }
        return words;
    }
};

// int main() {
//     Solution solution;
//     vector<string> words = {"cat", "tac", "dog", "god", "hello", "world"};
    
//     vector<string> result = solution.removeAnagrams(words);
    
//     cout << "결과 문자열 목록:" << endl;
//     for(const string& word : result) {
//         cout << word << endl;
//     }

//     return 0;
// }
