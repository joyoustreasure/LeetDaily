#include <stdio.h>
#include <string.h>

int countPrefixes(char **words, int wordsSize, char *s) {
    int count = 0;
    
    for(int i = 0; i < wordsSize; i++) {
        char *word = words[i];
        int len = strlen(word);
        
        // s의 부분 문자열을 가져와서 temp에 저장합니다.
        char temp[len + 1];
        strncpy(temp, s, len);
        temp[len] = '\0'; // Null-terminated string으로 만듭니다.
        
        if(strcmp(temp, word) == 0) {
            count++;
        }
    }
    
    return count;
}

// int main() {
//     char *words[] = {"hel", "world", "he"};
//     int wordsSize = sizeof(words) / sizeof(words[0]);
//     char s[] = "hello";
    
//     printf("접두사의 수: %d\n", countPrefixes(words, wordsSize, s));

//     return 0;
// }
