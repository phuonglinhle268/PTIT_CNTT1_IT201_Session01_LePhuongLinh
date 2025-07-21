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
void postOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderDFS(root -> left);
    postOrderDFS(root -> right);
    printf("%d ", root -> data);
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
    printf("PostOrder DFS: ");
    postOrderDFS(root);
    return 0;
}