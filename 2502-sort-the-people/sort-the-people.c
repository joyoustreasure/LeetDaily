#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[100];
    int height;
};

void bubbleSort(struct Person* people, int size) {
    int i, j;
    struct Person temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (people[j].height < people[j + 1].height) {
                // 키를 기준으로 내림차순으로 정렬
                temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // 사람들을 구조체 배열로 변환하여 정렬
    struct Person* people = malloc(namesSize * sizeof(struct Person));
    for (int i = 0; i < namesSize; i++) {
        strcpy(people[i].name, names[i]);
        people[i].height = heights[i];
    }

    // 버블 정렬로 구조체 배열 정렬
    bubbleSort(people, namesSize);

    // 정렬된 결과를 다시 문자열 배열로 변환하여 반환
    char** sortedNames = malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        sortedNames[i] = malloc((strlen(people[i].name) + 1) * sizeof(char));
        strcpy(sortedNames[i], people[i].name);
    }

    free(people);
    *returnSize = namesSize;
    return sortedNames;
}
