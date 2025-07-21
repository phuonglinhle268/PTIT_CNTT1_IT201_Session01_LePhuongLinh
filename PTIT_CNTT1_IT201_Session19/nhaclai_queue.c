#include <stdio.h>
#include <stdlib.h>

// typedef struct Node {
//     int data;
// }Node;

//b1: xdung cau truc hang doi
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
}Queue;

//ham khoi tao hang doi
Queue *createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue -> arr = (int*)malloc(sizeof(int) * capacity);
    queue -> capacity = capacity;
    queue -> front = 0;
    queue -> rear = -1;
}
//b2: xdung cac phuong thuc voi hang doi
//b2.1: them vao hang doi
void enQueue(Queue* queue, int data) {
    if (queue -> rear == queue -> capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> arr[++queue -> rear] = data;
}
//b2.2: ktra hang doi trong
int isEmpty(Queue* queue) {
    if (queue -> front > queue -> rear) {
        return 1;
    }
    return 0;
}
