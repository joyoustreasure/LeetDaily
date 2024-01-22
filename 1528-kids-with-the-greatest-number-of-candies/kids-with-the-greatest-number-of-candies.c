
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    int M = 0;
    for (int i=0; i<candiesSize;i++){
        if(candies[i]>M) M=candies[i];
    }
    for (int i=0; i<candiesSize;i++){
        candies[i]=candies[i]-M+extraCandies;
    }
    bool* result = malloc((candiesSize)*sizeof(bool));
    for (int i=0; i<candiesSize;i++){
        if(candies[i]>=0) result[i]=true;
        else result[i]=false;
    }
    *returnSize=candiesSize;
    return result;

}