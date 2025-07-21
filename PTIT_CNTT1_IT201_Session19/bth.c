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

//xdung ham duyet preOrder
void preOrderDFS(Node *root) {
    if (root == NULL) {
        return;   //diem dung, cay ko co nut nao
    }
    //in node dc xet
    printf("%d ", root -> data);
    //thuc hien bai toan con voi cay con ben trai
    preOrderDFS(root -> left);
    //thuc hien bai toan voi cay con ben phai
    preOrderDFS(root -> right);
}

//xdung ham duyet inOrder
void inOrderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    //thuc hien bai toan con voi cay con ben trai
    inOrderDFS(root -> left);
    //in ra node duoc xet
    printf("%d ", root -> data);
    //thuc hien voi cay con ben phai
    inOrderDFS(root -> right);
}

//xdung ham duyet postOrder
void postOrderDFS(Node *root) {
    if (root == NULL) {
        return;
    }
    //thuc hien bai toan voi cay con ben trai
    postOrderDFS(root -> left);
    //thuc hien bai toan voi cay con ben phai
    postOrderDFS(root -> right);
    //in node dc xet
    printf("%d ", root -> data);
}

// duyet BFS
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
void levelOrderDFS(Node *root) {
    //ktra cay trong
    if (root == NULL) {
        return;
    }
    //khoi tao hang doi
    Queue *queue = createQueue(100);
    //dua node goc vao hang doi
    enQueue(queue, root);
    //trien khai vong lap den khi hang doi trong
    while (!isEmpty(queue)) {
        //lay node dau hang doi va in ra
        Node *node = queue->arr[queue->front++];
        printf("%d ", node->data);
        //ktra, day cac node con cua node duoc in vao hang doi
        if (node -> left != NULL) {
            enQueue(queue, node -> left);
        }
        if (node -> right != NULL) {
            enQueue(queue, node -> right);
        }
    }
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
    printf("PreOrder DFS: \n");
    preOrderDFS(root);
    printf("\n");
    printf("InOrder DFS: \n");
    inOrderDFS(root);
    printf("\n");
    printf("PostOrder DFS: \n");
    postOrderDFS(root);
    printf("\n");
    printf("Level Order DFS: \n");
    levelOrderDFS(root);
}
