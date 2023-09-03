#include <stdio.h>

int minNumberOfHours(int initialEnergy, int initialExperience, int* energy, int energySize, int* experience, int experienceSize) {
    int hours = 0;
    int ie = initialEnergy;
    int ig = initialExperience;

    for (int i = 0; i < energySize; i++) {
        // 에너지가 부족하면 시간을 추가하고 에너지를 보충합니다.
        if (energy[i] >= ie) {
            hours += energy[i] - ie + 1;
            ie += energy[i] - ie + 1;
        }
        // 경험치가 부족하면 시간을 추가하고 경험치를 보충합니다.
        if (experience[i] >= ig) {
            hours += experience[i] - ig + 1;
            ig += experience[i] - ig + 1;
        }
        // 마지막으로 경험치를 더하고 에너지를 감소시킵니다.
        ie -= energy[i];
        ig += experience[i];
    }
    return hours;
}

// int main() {
//     int energy[] = {1, 2, 3};
//     int experience[] = {2, 1, 3};
//     int ie = 1;
//     int ig = 2;

//     printf("%d\n", minNumberOfHours(ie, ig, energy, sizeof(energy)/sizeof(energy[0]), experience, sizeof(experience)/sizeof(experience[0])));
//     // 예상 출력: 5
//     return 0;
// }
