int largestAltitude(int* gain, int gainSize) {
    int cur=0;
    int highest=0;
    for(int i=0;i<gainSize;i++){
        cur+=gain[i];
        if(cur>highest){highest = cur;}
    }
    return highest;
}