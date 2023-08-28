#include <stdbool.h>

bool isSameAfterReversals(int num) {
    if(num == 0) return true;
    if(num % 10 == 0) return false;
    return true;
}

// // C에서는 클래스가 없기 때문에 별도의 main 함수를 통해 함수를 호출합니다.
// int main() {
//     int testNum = 1230;  // 예시 입력 값
//     bool result = isSameAfterReversals(testNum);
//     if(result) {
//         printf("%d는 뒤집어도 동일합니다.\n", testNum);
//     } else {
//         printf("%d는 뒤집으면 동일하지 않습니다.\n", testNum);
//     }
//     return 0;
// }
