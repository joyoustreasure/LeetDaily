#include <string>
class Solution {
public:
    int minimumMoves(string s) {
        int cnt=0;
        int i=0;
        while (i<s.length()){
            if(s[i]=='X'){
                cnt+=1;
                i+=3;
            }
            else {i+=1;}
        }
        return cnt;
    }
};


