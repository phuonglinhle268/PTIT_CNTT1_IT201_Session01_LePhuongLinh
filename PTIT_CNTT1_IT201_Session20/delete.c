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
Node* delete(Queue* root, int data){
    //ktra hang doi ko co node nao
    if (root == NULL) {
        return NULL;
    }
    //khoi tao hang doi va dua root vao hang doi
    Queue* queue = createQueue(100);
    enQueue(queue, root);
    //khoi tao 3 bien: target, lastNode, lastParent
    Node* target = NULL;
    Node* lastNode = NULL;
    Node* lastParent = NULL;
    //trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //lay node dau hang doi
        Node* node = deQueue(root);
        //ktra node co gtri bang voi gtri can xoa
        if (node -> data == data) {
            target = node;
        }
        //ktra con ben trai
        if (node -> left != NULL) {
            //neu co thi dua vao hang doi
            enQueue(queue, node -> left);
            //cap nhat lastParent thanh node dc lay
            lastParent = node;
            //cap nhat lastNode thanh con ben trai
            lastNode = node -> left;
        }
        //ktra con con ben phai
        if (node -> right != NULL) {
            //neu co thi dua vao hang doi
            enQueue(queue, node -> right);
            //cap nhat lastParent thanh node dc lay
            lastParent = node;
            //cap nhat lastNode thanh con ben phai
            lastNode = node -> right;
        }
    }
    //neu ko tim thay, ket thuc ham
    if (target == NULL) {
        return root;
    }
    //xu li truong hop cay chi co node goc
    if (lastNode == NULL) {
        free(root);
        root = NULL;
    }
    //xoa node cuoi cung
    //gan du lieu lastNode vao target
    target -> data = lastNode -> data;
    //cap nhat con tro cua lastParent
    if (lastNode == lastParent -> left) {
        lastParent -> left = NULL;
    } else {
        lastParent -> right = NULL;
    }
    //giai phong lastNode
    free(lastNode);
    //giai phong cac vung nho can thiet va tra ve root
    free(queue -> arr);
    free(queue);
    return root;
}

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
