#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool valid(char *s) {
    int hcnt = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            return false;
        }
        if (s[i] == '-') {
            if (i-1 < 0 || !isalpha(s[i-1]) || i+1 >= len || !isalpha(s[i+1]) || hcnt >= 1) {
                return false;
            }
            hcnt++;
        }
        if (s[i] == '!' || s[i] == ',' || s[i] == '.') {
            if (i != len - 1) {
                return false;
            }
        }
    }
    return true;
}

int countValidWords(char *sentence) {
    int cnt = 0;
    char *word = strtok(sentence, " ");
    
    while (word != NULL) {
        if (valid(word)) {
            cnt++;
        }
        word = strtok(NULL, " ");
    }
    return cnt;
}

// int main() {
//     char sentence[] = "he bought 2 pencils, 3 erasers, and 1 pencil-sharpener.";
//     int result = countValidWords(sentence);
//     printf("Number of valid words: %d\\n", result);

//     return 0;
// }
