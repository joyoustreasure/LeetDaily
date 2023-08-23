#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    char key[MAX_SIZE];
    int value;
} HashMap;

int findValue(HashMap *map, int size, char *key) {
    for (int i = 0; i < size; i++) {
        if (strcmp(map[i].key, key) == 0) {
            return map[i].value;
        }
    }
    return -1;  // Not found
}

void insertOrUpdate(HashMap *map, int *size, char *key, int value) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(map[i].key, key) == 0) {
            map[i].value = value;
            return;
        }
    }
    strcpy(map[*size].key, key);
    map[*size].value = value;
    (*size)++;
}

char* kthDistinct(char **arr, int arrSize, int k) {
    HashMap map[MAX_SIZE];
    int size = 0;

    for (int i = 0; i < arrSize; i++) {
        int val = findValue(map, size, arr[i]);
        if (val == -1) {
            insertOrUpdate(map, &size, arr[i], 1);
        } else {
            insertOrUpdate(map, &size, arr[i], val + 1);
        }
    }

    for (int i = 0; i < arrSize; i++) {
        if (findValue(map, size, arr[i]) == 1) {
            k--;
            if (k == 0)
                return arr[i];
        }
    }
    return "";  // If k is more than the distinct strings
}

// int main() {
//     char *arr[] = {"a", "b", "c", "a", "b", "c", "d"};
//     int arrSize = sizeof(arr) / sizeof(arr[0]);
//     int k = 2;

//     char *result = kthDistinct(arr, arrSize, k);
//     if (strcmp(result, "") != 0)
//         printf("%d번째 고유한 문자열: %s\\n", k, result);
//     else
//         printf("%d번째 고유한 문자열이 존재하지 않습니다.\\n", k);

//     return 0;
// }
