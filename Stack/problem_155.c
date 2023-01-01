typedef struct {
    int *arr;
    int size;
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack *ms = malloc(sizeof(MinStack));
    ms->arr = NULL;
    ms->size = 0;
    ms->top = -1;
    return ms;
}

void minStackPush(MinStack* obj, int val) {
  if(obj->size == 0){
      obj->arr = malloc(sizeof(int));
      obj->size++;
  }
  else if(obj->top == (obj->size - 1)){
      obj->arr = realloc(obj->arr, sizeof(int) * (++(obj->size)));
  }
  obj->arr[++(obj->top)] = val;
  return;
}

void minStackPop(MinStack* obj) {
    obj->top--;
    return;
}

int minStackTop(MinStack* obj) {
  return obj->arr[obj->top];
}

int minStackGetMin(MinStack* obj) {
  int *a = obj->arr;
  int ind = obj->top;
  int min = a[ind];
  ind--;
  while(ind >= 0){
      if(a[ind] < min){
          min = a[ind];
      }
      ind--;
  }
  return min;
}

void minStackFree(MinStack* obj) {
    free(obj->arr);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
