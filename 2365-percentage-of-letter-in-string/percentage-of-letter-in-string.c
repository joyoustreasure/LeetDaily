#include <stdio.h>
#include <string.h>

int percentageLetter(char *s, char letter) {
    int count = 0;
    int length = strlen(s);

    for(int i = 0; i < length; i++) {
        if(s[i] == letter) {
            count++;
        }
    }

    return (count * 100) / length;
}

// int main() {
//     char s[] = "apple";
//     char letter = 'p';

//     int result = percentageLetter(s, letter);
//     printf("The letter '%c' appears in the word '%s' with a percentage of: %d%%\n", letter, s, result);

//     return 0;
// }
