void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    if(!k)
        return;
    int *stack = malloc(sizeof(int) * numsSize);
    int top = -1;
    for(int i = 0; i < numsSize - k; i++){
        stack[++top] = nums[i];
    }
    for(int j = numsSize - k; j < numsSize; j++){
        nums[j - (numsSize -  k)] = nums[j];
    }
    top = 0;
    for(int i = k; i < numsSize; i++){
        nums[i] = stack[top++];
    }
    return;
}
