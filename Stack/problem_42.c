int trap(int* height, int heightSize){
    int water = 0;
    int compute = 0;
    int *arr = malloc(sizeof(int) * heightSize);
    int top = -1;
    int front;
    int back;
    int ind;
    int h;
    for(int i = 0; i < heightSize; i++){
        if(top == -1){
            arr[++top] = height[i];
        }
        else if(height[i] <= arr[top]){
            arr[++top] = height[i];
        }
        else{
            ind = top - 1;
            while(ind >= 0 && arr[ind] < height[i]){
                ind--;
            }
            if(ind == -1){
                compute = arr[++ind] * top;
                h = arr[ind];
            }
            else{
                compute = height[i] * (top - ind);
                h = height[i];
            }
            for(int j = ind + 1; j <= top; j++){
                compute -= arr[j];
                arr[j] = h;
            }
            water += compute;
            if(height[i] > arr[ind]){
                top = 0;
                arr[top] = height[i];
            }
            else{
                arr[++top] = height[i];
            }
        }
    }
    return water;
}
