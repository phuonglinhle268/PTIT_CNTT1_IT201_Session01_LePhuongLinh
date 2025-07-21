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

int searchDFS(Node* root, int target) {
    if (root == NULL) {
        return;
    }
    if (root -> data == target) {
        return 1;
    }
    //return searchDFS(root -> left, target) || searchDFS(root -> right, target);
    if (searchDFS(root -> left, target)) {
        return 1;
    }
    if (searchDFS(root -> right, target)) {
        return 1;
    }
    return 0;
}
void preOrderDFS(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root -> data);
    preOrderDFS(root -> left);
    preOrderDFS(root -> right);
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
    preOrderDFS(root);
    printf("\n");
    int target;
    printf("\nfindValue: ");
    scanf("%d", &target);
    if (searchDFS(root, target)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }
    return 0;
}