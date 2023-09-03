#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

char * decodeMessage(char * key, char * message) {
    int table[26];
    for (int i = 0; i < 26; i++) {
        table[i] = -1;
    }

    int k = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        if (key[i] != ' ' && table[key[i]-'a'] == -1) {
            table[key[i]-'a'] = k++;
        }
    }

    char * decoded = (char *)malloc(strlen(message) + 1); // +1 for the null terminator
    strcpy(decoded, message);

    for (int i = 0; decoded[i] != '\0'; i++) {
        if (decoded[i] != ' ') {
            decoded[i] = table[decoded[i]-'a'] + 'a';
        }
    }

    return decoded;
}

// int main() {
//     char key[100], message[100];

//     printf("디코딩 키를 입력하세요: ");
//     gets(key);  // Using gets for simplicity, but it's unsafe and deprecated. Consider using fgets.

//     printf("디코딩할 메시지를 입력하세요: ");
//     gets(message);  // Using gets for simplicity, but it's unsafe and deprecated. Consider using fgets.

//     char *decoded = decodeMessage(key, message);
//     printf("디코딩된 메시지: %s\n", decoded);

//     free(decoded);  // Remember to free the allocated memory

//     return 0;
// }
