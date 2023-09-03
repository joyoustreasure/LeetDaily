#include <stdio.h>
#include <string.h>
#include <limits.h>

int minimumRecolors(char * blocks, int k) {
    int back = 0, front = 0, count_w = 0, ans = INT_MAX;
    int blocks_length = strlen(blocks);

    while(front < blocks_length) {
        if(blocks[front] == 'W') {
            count_w++;
        }
        if(front - back + 1 == k) {
            if(ans > count_w) {
                ans = count_w;
            }
            if(blocks[back] == 'W') {
                count_w--;
            }
            back++;
        }
        front++;
    }
    return ans;
}

// int main() {
//     char blocks[] = "BWBWWB";
//     int k = 3;
//     printf("%d\n", minimumRecolors(blocks, k));  // 예상 출력: 2
//     return 0;
// }
