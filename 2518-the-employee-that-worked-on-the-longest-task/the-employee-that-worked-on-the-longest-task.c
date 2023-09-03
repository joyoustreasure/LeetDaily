#include <stdio.h>
#include <stdlib.h>

int hardestWorker(int n, int** logs, int logsSize, int* logsColSize) {
    int last = 0, emp = 0, larg = 0, period;
    for (int i = 0; i < logsSize; i++) {
        period = logs[i][1] - last;
        if (larg == period)
            emp = emp < logs[i][0] ? emp : logs[i][0];
        else if (larg < period) {
            larg = period;
            emp = logs[i][0];
        }
        last = logs[i][1];
    }
    return emp;
}

// int main() {
//     int n;

//     printf("사원 수를 입력하세요: ");
//     scanf("%d", &n);

//     int logsSize = n;
//     int** logs = (int**)malloc(logsSize * sizeof(int*));
//     int* logsColSize = (int*)malloc(logsSize * sizeof(int));

//     for (int i = 0; i < logsSize; i++) {
//         int start, end;
//         printf("%d번째 사원의 출근 및 퇴근 시간을 입력하세요: ", i + 1);
//         scanf("%d %d", &start, &end);

//         logsColSize[i] = 2;
//         logs[i] = (int*)malloc(logsColSize[i] * sizeof(int));
//         logs[i][0] = start;
//         logs[i][1] = end;
//     }

//     int result = hardestWorker(n, logs, logsSize, logsColSize);
//     printf("가장 열심히 일한 사원 번호: %d\n", result);

//     // 메모리 해제
//     for (int i = 0; i < logsSize; i++) {
//         free(logs[i]);
//     }
//     free(logs);
//     free(logsColSize);

//     return 0;
// }
