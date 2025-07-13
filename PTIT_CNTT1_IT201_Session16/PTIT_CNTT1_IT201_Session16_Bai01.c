#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue(){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue -> front = NULL;
    queue -> rear = NULL;
    return queue;
}
int main() {
    Queue* newQueue = createQueue();
    if (newQueue != NULL && newQueue->front==NULL && newQueue->rear==NULL) {
        printf("Khoi tao thanh cong");
    } else {
        printf("Khoi tao that bai");
    }
    free(newQueue);
}