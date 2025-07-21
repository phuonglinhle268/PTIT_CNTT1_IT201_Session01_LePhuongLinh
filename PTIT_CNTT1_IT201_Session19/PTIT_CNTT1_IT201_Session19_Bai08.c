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
int chieu_cao(Node* root) {
    if (root == NULL) {
        return;
    }
    int leftHeight = chieu_cao(root -> left);
    int rightHeight = chieu_cao(root -> right);
    int max;
    //chieu cao lon nhat giua cay con trai-phai
    if (leftHeight > rightHeight) {
        max = leftHeight;
    } else {
        max = rightHeight;
    }
    return 1+max; //1 la nit hien tai ban dau (root)
    // root + chieu cao cua cay con ben duoi -> tong toan cay
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
    printf("Chieu cao cua cay: %d\n", chieu_cao(root));
    return 0;
}
