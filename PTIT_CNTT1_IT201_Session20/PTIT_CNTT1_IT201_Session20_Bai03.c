#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

typedef struct Queue {
    Node** arr;
    int capacity;
    int front;
    int rear;
}Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}
Queue* createQueue(int capacity) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue -> arr = (Node**)malloc(capacity * sizeof(Node*));
    newQueue -> capacity = capacity;
    newQueue -> front = 0;
    newQueue -> rear = -1;
    return newQueue;
}
int isEmpty(Queue* queue) {
    return queue -> rear < queue -> front;
}
void enQueue(Queue* queue, Node* node) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue -> arr[++queue->rear] = node;
}
Node* deQueue(Queue* queue) {
    return queue -> arr[queue -> front++];
}
void preOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root -> data);
    preOrderDFS(root -> left);
    preOrderDFS(root -> right);
}
void insertNode(Node* root, int value) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(100);
    enQueue(queue, root);
    while (!isEmpty(queue)) {
        Node* current = deQueue(queue);
        if (current -> left == NULL) {
            current -> left = createNode(value);
            break;
        } else {
            enQueue(queue, current -> left);
        }
        if (current -> right == NULL) {
            current -> right = createNode(value);
            break;
        } else {
            enQueue(queue, current -> right);
        }
    }
}
int main() {
    Node* root = NULL ;
    root = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    root -> left = node3;
    root -> right = node4;
    node3 -> left = node5;
    printf("Cay ban dau: \n");
    preOrderDFS(root);
    printf("\n");
    int value;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    insertNode(root, value);
    printf("Cay sau khi them: ");
    preOrderDFS(root);
    return 0;
}
