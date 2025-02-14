#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int* queue;
    int front;
    int rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->queue = (int*)malloc(sizeof(int) * k);
    obj->front = obj->rear = -1;
    obj->size = k;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if ((obj->rear + 1) % obj->size == obj->front) {
        return false;
    }
    if (obj->front == -1) {
        obj->front = 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->queue[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->front == -1) {
        return false;
    }
    if (obj->front == obj->rear) {
        obj->front = obj->rear = -1;
    } else {
        obj->front = (obj->front + 1) % obj->size;
    }
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->front == -1) {
        return -1;
    }
    return obj->queue[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->rear == -1) {
        return -1;
    }
    return obj->queue[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == -1;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % obj->size == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->queue);
    free(obj);
}


/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/