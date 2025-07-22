#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

//Duyet bang preOrder
void preOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root -> data);
    preOrderDFS(root -> left);
    preOrderDFS(root -> right);
}

//Duyet bang inOrder
void inOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderDFS(root -> left);
    printf("%d ", root -> data);
    inOrderDFS(root -> right);
}

//Duyet bang postOrder
void postOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderDFS(root -> left);
    postOrderDFS(root -> right);
    printf("%d ", root -> data);
}

//Duyet bang levelOrder
typedef struct Queue {
    Node** arr;
    int capacity;
    int front;
    int rear;
}Queue;
Queue* createQueue(int capacity) {
    Queue* newQueue = (Queue*)malloc(sizeof(Queue));
    newQueue -> arr = (Node**)malloc(capacity * sizeof(Node*));
    newQueue -> capacity = capacity;
    newQueue -> front = 0;
    newQueue -> rear = -1;
    return newQueue;
}
void enQueue(Queue *queue, Node *node) {
    if (queue -> rear == queue -> capacity -1) {
        printf("Queue is full\n");
        return;
    }
    queue -> arr[++queue -> rear] = node;
}
int isEmpty(Queue* queue) {
    return queue -> rear < queue -> front;
}
void levelOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(100);
    enQueue(queue, root);
    while (!isEmpty(queue)) {
        Node* node = queue -> arr[queue -> front++];
        printf("%d ", node -> data);
        if (node -> left != NULL) {
            enQueue(queue, node -> left);
        }
        if (node -> right != NULL) {
            enQueue(queue, node -> right);
        }
    }
}

int main() {
    Node* root = NULL;
    root = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    root -> left = node3;
    root -> right = node4;
    node3 -> left = node5;
    printf("\nPreOrder DFS: ");
    preOrderDFS(root);
    printf("\n");
    printf("\nInOrder DFS: ");
    inOrderDFS(root);
    printf("\n");
    printf("\nPostOrder DFS: ");
    postOrderDFS(root);
    printf("\n");
    printf("\nLevel Order DFS: ");
    levelOrderDFS(root);
    printf("\n");
    return 0;
}