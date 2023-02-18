typedef struct {
    int *q;
    int front;
    int rear;
    int size;
    int count;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *cq = malloc(sizeof(MyCircularQueue));
    cq->q = malloc(sizeof(int) * k);
    cq->front = -1;
    cq->rear = -1;
    cq->size = k;
    cq->count = 0;
    return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if(obj->count == obj->size)
        return false;
    obj->rear = (obj->rear + 1) % obj->size;
    obj->q[obj->rear] = value;
    obj->count++;
    if(obj->count == 1)
        obj->front = 0;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(!obj->count)
        return false;
    if(obj->count == 1){
        obj->front = obj->rear = -1;
    }
    else{
        obj->front = (obj->front + 1) % obj->size;
    }
    obj->count--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(!obj->count)
        return -1;
    return obj->q[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(!obj->count)
        return -1;
    return obj->q[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return !obj->count;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->count == obj->size;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->q);
    free(obj);
}
