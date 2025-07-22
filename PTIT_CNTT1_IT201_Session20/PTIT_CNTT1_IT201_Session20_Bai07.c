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
void levelOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    Queue* queue = createQueue(100);
    enQueue(queue, root);
    while (!isEmpty(queue)) {
        Node* current = deQueue(queue);
        printf("%d ", current -> data);
        if (current -> left) {
            enQueue(queue, current -> left);
        }
        if (current -> right) {
            enQueue(queue, current -> right);
        }
    }
}
void deleteNode(Node* root, int key) {
    if (root == NULL) {
        return;
    }
    if (root -> left == NULL && root -> right == NULL) {
        if (root -> data == key) {
            free(root);
            root = NULL;
        } else {
            printf("Khong tim thay gia tri\n");
        }
        return;
    }
    Queue* queue = createQueue(100);
    enQueue(queue, root);
    Node* target = NULL;
    Node* current = NULL;
    Node* lastParent = NULL;
    while (!isEmpty(queue)) {
        current = deQueue(queue);
        if (current -> data == key) {
            target = current;
        }
        if (current -> left) {
            enQueue(queue, current -> left);
            lastParent = current;
        }
        if (current -> right) {
            enQueue(queue, current -> right);
            lastParent = current;
        }
    }
    if (target) {
        target -> data = current -> data;
        if (lastParent -> right == current) {
            free(lastParent -> right);
            lastParent -> right = NULL;
        } else if (lastParent -> left == current) {
            free(lastParent -> left);
            lastParent -> left = NULL;
        }
    } else {
        printf("Khong tim thay gia tri\n");
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
    levelOrder(root);
    printf("\n");
    int value;
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &value);
    deleteNode(root, value);
    printf("Cay sau khi xoa: ");
    levelOrder(root);
    return 0;
}
