#include <stdbool.h>
#include <string.h>

bool checkString(char* s) {
    int length = strlen(s);
    for(int i = 1; i < length; i++) {
        if(s[i - 1] == 'b' && s[i] == 'a') {
            return false;
        }
    }
    return true;
}
