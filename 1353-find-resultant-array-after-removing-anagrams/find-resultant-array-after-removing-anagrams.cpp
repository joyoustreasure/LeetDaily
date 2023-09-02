#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        for(int i = 1; i < words.size(); i++) {
            string x = words[i];
            sort(x.begin(), x.end());
            
            string y = words[i-1];
            sort(y.begin(), y.end());
            
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
