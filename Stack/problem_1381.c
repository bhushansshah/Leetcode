typedef struct {
    int *s;
    int count;
    int size;
    int top;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {
    CustomStack *cs = malloc(sizeof(CustomStack));
    cs->count = 0;
    cs->size = maxSize;
    cs->top = -1;
    cs->s = malloc(sizeof(int) * maxSize);
    return cs;
}

void customStackPush(CustomStack* obj, int x) {
  if(obj->count == obj->size){
    return;
  }
  obj->s[++(obj->top)] = x;
  obj->count++;
}

int customStackPop(CustomStack* obj) {
    if(obj->count == 0){
        return -1;
    }
    int result = obj->s[obj->top];
    obj->top--;
    obj->count--;
    return result;
}

void customStackIncrement(CustomStack* obj, int k, int val) {
    int flag, ele;
    if(obj->count == 0)
        return;
    flag = (obj->count <= k);
    ele = customStackPop(obj);
    customStackIncrement(obj, k, val);
    if(flag){
        ele += val;
    }
    customStackPush(obj, ele);
}

void customStackFree(CustomStack* obj) {
    free(obj->s);
    free(obj);
}
