int maxDistance(int* colors, int colorsSize){
int max = 0;
int* a = colors;
int* b = colors;
for (int i=0; i<colorsSize;i++){
    int p1 = *(a+i);
    for(int j=i+1; j<colorsSize;j++){
        int p2 = *(b+j);
        if (p1!=p2 && (j-i)>max){max = j-i;}
    }
}
return max;
}