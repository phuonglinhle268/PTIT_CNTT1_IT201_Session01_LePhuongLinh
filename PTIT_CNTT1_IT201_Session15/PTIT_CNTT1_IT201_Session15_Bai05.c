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
int deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong");
        return -1;
    }
    int value = queue -> arr[queue -> front];
    queue -> front++;
    return value;
}
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Hang doi rong\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue -> arr[i]);
    }
    printf("\n");
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
    if (newQueue != NULL) {
        printf("Khoi tao thanh cong\n");
    } else {
        printf("Khoi tao that bai\n");
    }
    printf("Phan tu trong hang doi: ");
    enQueue(newQueue, 1);
    enQueue(newQueue, 2);
    enQueue(newQueue, 3);
    printQueue(newQueue);
    int delete = deQueue(newQueue);
    if (delete != -1) {
        printf("Da xoa phan tu %d\n", delete);
    }
    printQueue(newQueue);
    freeQueue(newQueue);
}
