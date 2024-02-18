void reverse(char* start, char* end) {
    char temp;
    while (end > start) {
        temp = *end;
        *end = *start;
        *start = temp;
        start++;
        end--;
    }
}

char* reverseWords(char* s) {
    int len = strlen(s);


    int i, j;
    for (i = 0, j = 0; i < len; ++i) {
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' ')) {
            s[j++] = s[i];
        }
    }

    if (j > 0 && s[j - 1] == ' ') {
        j--;
    }

    s[j] = '\0';

    len = j;


    reverse(s, s + len - 1);


    for (i = 0, j = 0; i < len; ++i) {
        if (s[i] == ' ') {
            reverse(s + j, s + i - 1);
            j = i + 1;
        }
    }


    reverse(s + j, s + len - 1);

    return s;
}