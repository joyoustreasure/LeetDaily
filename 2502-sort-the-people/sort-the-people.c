#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 정의: 이름과 키를 함께 저장하기 위함
struct Person {
    char name[100];
    int height;
};

// 정렬에 사용될 비교 함수
int compare(const void* a, const void* b) {
    // 내림차순으로 정렬하도록 비교 함수 구현
    return ((struct Person*)b)->height - ((struct Person*)a)->height;
}

// 함수 정의
char ** sortPeople(char ** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // 사람들을 구조체 배열로 변환하여 정렬
    struct Person* people = malloc(namesSize * sizeof(struct Person));
    for (int i = 0; i < namesSize; i++) {
        strcpy(people[i].name, names[i]);  // 이름을 구조체에 복사
        people[i].height = heights[i];     // 키를 구조체에 저장
    }
    qsort(people, namesSize, sizeof(struct Person), compare); // 구조체 배열 정렬

    // 정렬된 결과를 다시 문자열 배열로 변환하여 반환
    char** sortedNames = malloc(namesSize * sizeof(char*));
    for (int i = 0; i < namesSize; i++) {
        // 정렬된 구조체에서 이름을 추출하여 문자열을 동적 할당
        sortedNames[i] = malloc((strlen(people[i].name) + 1) * sizeof(char));
        strcpy(sortedNames[i], people[i].name);
    }

    free(people); // 구조체 배열을 메모리에서 해제
    *returnSize = namesSize; // 반환할 배열 크기 설정
    return sortedNames; // 정렬된 이름들을 가리키는 포인터 배열 반환
}
