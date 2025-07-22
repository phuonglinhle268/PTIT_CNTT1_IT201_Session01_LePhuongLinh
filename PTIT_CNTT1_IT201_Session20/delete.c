#include <stdio.h>
#include <stdlib.h>

//xdung cau truc 1 node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

//xdung ham khoi tao
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//xdung cau truc hang doi
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
}Queue;
//ham khoi tao
Queue *createQueue(int capacity) {
    Queue *newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue -> arr = (Node**)malloc(capacity * sizeof(Node*));
    newQueue -> capacity = capacity;
    newQueue -> front = 0;
    newQueue -> rear = -1;
    return newQueue;
}
void enQueue(Queue *queue, Node *node) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    //day ptu vao hang doi
    queue -> arr[++queue->rear] = node;
}
//ktra hang doi trong
int isEmpty(Queue *queue) {
    return queue->rear < queue -> front;
}
Node *deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    return queue->arr[queue->front++];
}
//xdung ham xoa vao cay


int main() {
    Node *root = NULL;
    root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;

}
