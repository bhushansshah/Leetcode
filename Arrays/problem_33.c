
int search(int* nums, int numsSize, int target){
    int i = 0;
    int p1, p2, mid;
	//Finding the pivot point.
    while(true){
        if(i == numsSize - 1){
            break;
        }
        if(nums[i] > nums[i + 1]){
            break;
        }
        i++;
    }
	//Deciding whelther target belongs to left portion or the right portion.
    if(i == numsSize - 1){
        p1 = 0;
        p2 = numsSize - 1;
    }
    else if(target == nums[numsSize - 1]){
        return numsSize - 1;
    }
    else if(target < nums[numsSize - 1]){
        p1 = i + 1;
        p2 = numsSize - 1;
    }
    else{
        p1 = 0;
        p2 = i;
    }
    
    while(p1 <= p2){
        mid = (p1 + p2) / 2;
        if(target == nums[mid]){
            return mid;
        }
        else if(target > nums[mid]){
            p1 = mid + 1;
        }
        else{
            p2 = mid - 1;
        }
    }
    return -1;
}
