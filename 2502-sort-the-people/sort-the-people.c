#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    int height;
} Person;

int compare(const void *a, const void *b) {
    return ((Person*)b)->height - ((Person*)a)->height; // descending order
}

char** sortPeople(char **names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // Check if namesSize and heightsSize are equal. If not, return NULL.
    if (namesSize != heightsSize) {
        *returnSize = 0;
        return NULL;
    }

    // Create an array of Person structures
    Person people[namesSize];
    for(int i = 0; i < namesSize; i++) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // Sort the array of structures based on height
    qsort(people, namesSize, sizeof(Person), compare);

    // Create an array to store sorted names
    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));
    for(int i = 0; i < namesSize; i++) {
        sortedNames[i] = people[i].name;
    }
    
    *returnSize = namesSize;
    return sortedNames;
}
