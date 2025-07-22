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
void preOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root -> data);
    preOrderDFS(root -> left);
    preOrderDFS(root -> right);
}
int count(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root -> left == NULL && root -> right == NULL) {
        return 1;
    }
    return count(root->left) + count(root->right);
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
    printf("Cay ban dau: ");
    preOrderDFS(root);
    printf("\n");
    int leaves = count(root);
    printf("So nut la trong cay: %d\n", leaves);
    return 0;
}
