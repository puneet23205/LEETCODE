
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->data = (int*)malloc(size * sizeof(int));
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->front == -1;
}

void enqueue(Queue* queue, int value) {
    if (queue->rear == queue->size - 1) {
        return; 
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->data[queue->rear] = value;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -1; 
    }
    int value = queue->data[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return value;
}

typedef struct {
    Queue* q1;
    Queue* q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = createQueue(100);
    stack->q2 = createQueue(100);
    return stack;
}

void myStackPush(MyStack* obj, int x) {
    enqueue(obj->q1, x);
}

int myStackPop(MyStack* obj) {
    while (obj->q1->front != obj->q1->rear) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int value = dequeue(obj->q1);
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return value;
}

int myStackTop(MyStack* obj) {
    while (obj->q1->front != obj->q1->rear) {
        enqueue(obj->q2, dequeue(obj->q1));
    }
    int value = dequeue(obj->q1);
    enqueue(obj->q2, value);
    Queue* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    return value;
}

bool myStackEmpty(MyStack* obj) {
    return isEmpty(obj->q1);
}

void myStackFree(MyStack* obj) {
    free(obj->q1->data);
    free(obj->q1);
    free(obj->q2->data);
    free(obj->q2);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/