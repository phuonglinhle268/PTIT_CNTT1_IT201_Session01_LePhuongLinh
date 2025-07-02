#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}
Node* insertNode(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode -> next = head;
    return newNode;
}
int main() {
    Node* head = NULL;
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    displayList(head);

    int n;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &n);
    if (n>0) {
        printf("Danh sach moi: ");
        displayList(insertNode(head, n));
    } else {
        printf("Gia tri khong hop le");
    }
}
