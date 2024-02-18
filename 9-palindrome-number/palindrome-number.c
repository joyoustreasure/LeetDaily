
bool isPalindrome(int x) {
    int originalNum = x;
    long long reversedNum = 0;

    // 숫자 뒤집기
    while (x > 0) {
        int digit = x % 10;
        reversedNum = reversedNum * 10 + digit;
        x /= 10;
    }

    // 원래 숫자와 뒤집힌 숫자 비교
    if (originalNum == reversedNum) {
        return true; // 팰린드롬인 경우
    } else {
        return false; // 팰린드롬이 아닌 경우
    }
}