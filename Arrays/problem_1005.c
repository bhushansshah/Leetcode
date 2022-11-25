int cmpfunc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;    
}
int largestSumAfterKNegations(int* nums, int numsSize, int k){
    int sum = 0;
    int min;
    int ind;
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
    }
    
    qsort(nums, numsSize, sizeof(int), cmpfunc);
    ind = 0;
    if(nums[0] > 0){
        if(k % 2){
            sum += -2 * nums[0];
        }
    }
    else{
        while(nums[ind] < 0){
            nums[ind] *= -1;
            sum += 2 * nums[ind];
            k--;
            ind++;
            if(ind == numsSize){
                ind--;
                break;
            }
            if(k == 0){
                break;
            }
        }
        if(k % 2){
            if(nums[ind] < nums[ind - 1]){
                sum += -2 * nums[ind];
            }
            else{
                sum += -2 * nums[ind - 1];
            }
        }
    }
    return sum;
}
