void sortColors(int* nums, int numsSize){
    int temp;
    int ind = 0;
    for(int color = 0; color < 3; color++){
        for(int j = ind; j < numsSize; j++){
            if(nums[j] == color){
                temp = nums[ind];
                nums[ind++] = nums[j];
                nums[j] = temp;
            }
        }
    }
}
