bool winnerOfGame(char *colors) {
    int a = 0;
    int b = 0;
    char* cur = colors;

   while (*(cur) != '\0' && *(cur + 1) != '\0' && *(cur + 2) != '\0')
 {
        if (*(cur) == 'A' && *(cur + 1) == 'A' && *(cur + 2) == 'A') {
            a += 1;
        } else if (*(cur) == 'B' && *(cur + 1) == 'B' && *(cur + 2) == 'B') {
            b += 1;
        }
        cur++;
    }

    return a > b;
}
