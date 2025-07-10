#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;   //cap phat bo nho that bai
    }
    queue -> front = 0;
    queue -> rear = -1;
    queue -> capacity = capacity;
    queue -> arr = (int*)malloc(sizeof(int) * capacity);

    return queue;
}
int main() {
    int n;
    printf("Nhap so luong phan tu trong hang doi: ");
    scanf("%d", &n);
    Queue* newQueue = createQueue(n);
    if (newQueue != NULL) {
        printf("Khoi tao thanh cong");
    } else {
        printf("Khoi tao that bai");
    }
}
