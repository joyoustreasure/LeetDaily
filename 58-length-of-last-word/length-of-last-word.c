int lengthOfLastWord(char* s) {
    int cnt = 0;
    int lastWordLength = 0;
    int length = strlen(s);

    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') {
            if (cnt > 0) {
                lastWordLength = cnt;
            }
            cnt = 0;
        } 
        else {
            cnt++;
        }
    }

    if (cnt > 0) {
        lastWordLength = cnt;
    }

    return lastWordLength;
}