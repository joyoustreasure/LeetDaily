#include <iostream>
#include <vector>

using namespace std;

// 구조체 대신 클래스를 사용하여 이름과 키를 함께 저장하기 위함
class Person {
public:
    string name;
    int height;
};

// 수동 정렬 함수 (버블 정렬)
void manualSort(vector<Person>& people) {
    int n = people.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (people[j].height < people[j + 1].height) {
                // 키가 더 큰 순으로 정렬하기 위해 swap
                swap(people[j], people[j + 1]);
            }
        }
    }
}

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Person 클래스를 이용하여 사람들을 저장하는 배열 생성
        vector<Person> people;
        for (int i = 0; i < names.size(); i++) {
            Person person;
            person.name = names[i];
            person.height = heights[i];
            people.push_back(person);
        }

        // 수동으로 정렬
        manualSort(people);

        // 정렬된 결과를 문자열 벡터로 변환하여 반환
        vector<string> sortedNames;
        for (int i = 0; i < people.size(); i++) {
            sortedNames.push_back(people[i].name);
        }

        return sortedNames;
    }
};
