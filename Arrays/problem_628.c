int maximumProduct(int* nums, int numsSize){
    // int max;
    // int ind;
    // int temp;
    // for(int i = 0; i < numsSize; i++){
    //     max = nums[numsSize - 1 - i];
    //     ind = numsSize - 1 - i;
    //     for(int j = 0; j < numsSize - 1 - i; j++){
    //         if(nums[j] > max){
    //             max = nums[j];
    //             ind = j;
    //         }
    //     }
    //     nums[ind] = nums[numsSize - 1 - i];
    //     nums[numsSize - 1 - i] = max;
    // }
    // if(nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3] > nums[0] * nums[1] * nums[numsSize - 1]){
    //         return nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];
    // }
    // else{
    //     return nums[0] * nums[1] * nums[numsSize - 1];
    // }
    int max1, max2, max3, min1, min2;
    max1 = max2 = max3 = INT_MIN;
    min1 = min2 = INT_MAX;
    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max1){
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        }
        else if(nums[i] > max2){
            max3 = max2;
            max2 = nums[i];
        }
        else if(nums[i] > max3){
            max3 = nums[i];
        }
        if(nums[i] < min1){
            min2 = min1;
            min1 = nums[i];
        }
        else if(nums[i] < min2){
            min2 = nums[i];
        }
    }
    if(max1 * max2 * max3 > min1 * min2 * max1){
        return max1 * max2 * max3;
    }
    else{
        return min1 * min2 * max1;
    }
}
