#include <stdio.h>

int minBitFlips(int start, int goal) 
{
    int flips = 0;

    // start와 goal 둘 다 0이 될 때까지 반복합니다.
    while(start || goal)
    {
        // 현재 비트가 다르다면 비트 플립이 필요합니다.
        if((start % 2) != (goal % 2))
            flips++;

        // 다음 비트로 이동합니다.
        start /= 2;
        goal /= 2;
    }
    return flips;
}

// int main() {
//     int start = 10;
//     int goal = 3;
//     int result = minBitFlips(start, goal);
//     printf("최소 비트 플립 횟수: %d\n", result);
//     return 0;
// }
