#include <stdio.h>

int finalValueAfterOperations(char **operations, int operationsSize) {
    int x = 0;

    for (int i = 0; i < operationsSize; ++i) {
        if (operations[i][1] == '+') {
            x += 1;
        } else {
            x -= 1;
        }
    }

    return x;
}