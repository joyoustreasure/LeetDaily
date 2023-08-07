#include <stdio.h>
#include <string.h>

int minimumMoves(char *s) {
    int ans = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'X') {
            ans++;
            i += 2;
        }
    }
    return ans;
}