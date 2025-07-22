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
int findLevel(Node* root, int a, int level) {
    if (root == NULL) {
        return -1;
    }
    if (root -> data == a) {
        return level;
    }
    int leftSide = findLevel(root -> left, a, level+1);
    if (leftSide != -1) {
        return leftSide;   //khi da tim thay o nhanh trai thi return
        //left == -1 la ko tim thay
    }
    return findLevel(root -> right, a, level+1);
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
    int a;
    printf("Nhap gia tri muon tim tang: ");
    scanf("%d", &a);
    int level = findLevel(root, a, 0);
    //root: nut goc | a: gtri muon find level | 0: tang ban dau
    if (level != -1) {
        printf("Node level: %d", level);
    } else {
        printf("Khong co gia tri trong cay");
    }
    return 0;
}


