#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool equalFrequency(char * word) {
    int mp[26] = {0}; 

    for(int i = 0; i < strlen(word); i++) {
        mp[word[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(mp[i] == 0) continue; 

        mp[i]--;
        int fl = 0, cnt = 0, fl2 = 0;
        for(int j = 0; j < 26; j++) {
            if(mp[j] == 0) continue; 

            if(fl == 0) {
                cnt = mp[j];
                fl = 1;
            }

            if(mp[j] != cnt) {
                fl2 = 1;
                break;
            }
        }

        if(fl2 == 0) return true;

        mp[i]++;
    }
    return false;
}

// int main() {
//     char word[100];
//     printf("Enter a word: ");
//     scanf("%s", word);

//     if(equalFrequency(word)) {
//         printf("All characters in the word have the same frequency.\n");
//     } else {
//         printf("All characters in the word do not have the same frequency.\n");
//     }

//     return 0;
// }
