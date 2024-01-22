char * mergeAlternately(char * word1, char * word2){
int len1 = strlen(word1);
int len2 = strlen(word2);

char *result = malloc((len1+len2+1)*sizeof(char));
int i = 0;
int j = 0;
while (j<len1 || j<len2){
    if (j<len1) result[i++] = word1[j];
    if (j<len2) result[i++] = word2[j];
    j++;
}
result[i] = '\0';
return result;

}