int findMiddleIndex(int* nums, int numsSize){
    if(numsSize == 1)
        return 0;
    int sumLeft = 0;
    int sumRight = 0;
    for(int i = 1; i < numsSize; i++){
        sumRight += nums[i];
    }
    int ind = 0;
    while(ind < numsSize){
        if(sumLeft == sumRight){
            return ind;
        }
        sumLeft += nums[ind];
        ind++;
        if(ind < numsSize)
            sumRight -= nums[ind];
    }
    return -1;
}
