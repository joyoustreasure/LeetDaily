#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    int goal = strlen(s);
    int len = strlen(t);
    int start = 0;

    for (int j = 0; j < goal; j++) {
        int flag = 0;
        for (int i = start; i < len; i++) {
            if (s[j] == t[i]) {
                flag = 1;
                start = i + 1; 
                break; 
            }
        }
        if (flag == 0) {
            return false; 
        }
    }
    return true; 
}
