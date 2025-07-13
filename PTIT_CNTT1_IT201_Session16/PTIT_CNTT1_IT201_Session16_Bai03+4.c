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

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue -> front = NULL;
    queue -> rear = NULL;
    return queue;
}
void enQueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return;    //ko tao dc node moi
    }
    newNode -> data = value;
    newNode -> next = NULL;
    if (queue -> rear == NULL) {
        queue -> front = queue -> rear = newNode;
    } else {
        queue -> rear -> next = newNode;
        queue -> rear = newNode;
    }
}
void first(Queue* queue) {
    if (queue -> front == NULL) {
        printf("queue is empty");
    } else {
        printf("Phan tu dau tien la: %d", queue -> front -> data);
    }
}
void printQueue(Queue* queue) {
    Node* temp = queue -> front;    //dai dien cho hang doi duyet dsach ma ko anh huong queue
    if (temp == NULL) {
        printf("Hang doi rong");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}
void freeQueue(Queue* queue) {
    Node* current = queue -> front;
    while (current != NULL) {
        Node* temp = current -> next;
        free(temp);
    }
    free(queue);
}
int main() {
    Queue* newQueue = createQueue();
    if (newQueue != NULL) {
        printf("Khoi tao thanh cong");
    } else {
        printf("Khoi tao that bai");
        return 1;
    }
    enQueue(newQueue, 1);
    enQueue(newQueue, 2);
    enQueue(newQueue, 3);
    printf("\nHang doi co cac phan tu: ");
    printQueue(newQueue);
    first(newQueue);
    freeQueue(newQueue);
}

