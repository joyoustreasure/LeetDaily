int isPalindrome(char* s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

int countSubstrings(char* s) {
    int n = strlen(s);
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(s, i, j)) {
                count++;
            }
        }
    }

    return count;
}