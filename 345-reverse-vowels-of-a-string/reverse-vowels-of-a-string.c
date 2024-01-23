   int isVowel(char c) {

        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
        else return 0 ;
    }
char* reverseVowels(char* s) {
    int n = strlen(s);

    char* result = (char*)malloc((n + 1) * sizeof(char));
    int l=0;
    int r=n-1;
    while(l<r){
        while(l<r & isVowel(s[l])==0)l++;
        while(l<r & isVowel(s[r])==0)r--;
        char temp=s[l];
        s[l]=s[r];
        s[r]=temp;
        l++;
        r--;
    }
    return s;

}