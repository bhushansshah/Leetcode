 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize){
    int* arrp = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;
    int even = 0;
    int odd = 1;
    int temp;
    while(!(even >= numsSize || odd >= numsSize)){
        if(nums[even] % 2 == 0 && nums[odd] % 2 == 1){
            arrp[even] = nums[even];
            arrp[odd] = nums[odd];
            even += 2;
            odd += 2;
        }
        else if(nums[even] % 2 == 1 && nums[odd] % 2 == 0){
            /*temp = nums[even];
            nums[even] = nums[odd];
            nums[odd] = temp;*/
            arrp[even] = nums[odd];
            arrp[odd] = nums[even];
            even += 2;
            odd += 2;
        }
        else if(nums[even] % 2 == 0){
            arrp[even] = nums[even];
            even += 2;
        }
        else{
            arrp[odd] = nums[odd];
            odd += 2;
        }
    }
    while(even < numsSize){
        arrp[even] = nums[even];
        even += 2;
    }
    while(odd < numsSize){
        arrp[odd] = nums[odd];
        odd += 2;
    }
    return arrp;
}
