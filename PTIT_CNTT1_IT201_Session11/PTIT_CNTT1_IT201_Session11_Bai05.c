#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
void displayList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}
Node* insertNode(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode -> next = head;
    if (head != NULL) {
        head -> prev = newNode;
    }
    return newNode;
}
int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    Node* head = node1;
    node1 -> next = node2;
    node2 -> prev = node3;
    node2 -> next = node3;

    node3 -> prev = node2;
    node3 -> next = node4;

    node4 -> prev = node3;
    node4 -> next = node5;

    node5 -> prev = node4;
    displayList(head);

    int n;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &n);
    head = insertNode(head, n);
    displayList(head);
}

