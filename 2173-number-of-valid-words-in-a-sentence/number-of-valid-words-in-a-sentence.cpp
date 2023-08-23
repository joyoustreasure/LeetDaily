#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    bool valid(string &s) {
        int hcnt = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                return false;
            }
            if (s[i] == '-') {
                if (i-1 < 0 || !isalpha(s[i-1]) || i+1 >= s.length() || !isalpha(s[i+1]) || hcnt >=1 ) {
                    return false;
                }
                ++hcnt;
            }
            if (s[i] == '!' || s[i] == ',' || s[i] == '.') {
                if (i != s.length() - 1) {
                    return false;
                }
            }
        }
        return true;
    }

    int countValidWords(string sentence) {
        int cnt = 0;
        stringstream s(sentence);
        string word;
        while (s >> word) {
            if (valid(word)) {
                cnt++;
            }
        }
        return cnt;
    }
};
