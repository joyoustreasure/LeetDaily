int smallestEqual(int* nums, int numsSize){
for (int i = 0; i<numsSize; i++){
    if (i%10==*nums){return i;}
    else {nums+=1;}
}
return -1;

}