#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
}Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue -> arr = (int*)malloc(sizeof(int) * capacity);
    queue -> front = 0;
    queue -> rear = -1;
    queue -> capacity = capacity;
    return queue;
}
//ktra hang doi trong
int isEmpty(Queue* queue) {
    if (queue -> rear < queue -> front) {
        return 1;
    }
    return 0;
}
void enQueue(Queue* queue, int value) {
    if (queue -> rear >= queue -> capacity -1) {
        printf("Hang doi da day");
        return;
    }
    queue -> rear++;
    queue -> arr[queue -> rear] = value;
}
void freeQueue(Queue* queue) {
    if (queue != NULL) {
        free(queue -> arr);
        free(queue);
    }
}
int main() {
    int n;
    printf("Nhap so luong phan tu toi da trong hang doi: ");
    scanf("%d", &n);
    Queue* newQueue = createQueue(n);

    printf("Phan tu trong hang doi: ");
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        enQueue(newQueue, a);
    }
    int check = 1;
    for (int i = newQueue->front + 1; i <= newQueue->rear; i++) {
        if (newQueue -> arr[i] != newQueue -> arr[i-1] + 1) {
            check = 0;
        }
    }
    if (check) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    freeQueue(newQueue);
}

