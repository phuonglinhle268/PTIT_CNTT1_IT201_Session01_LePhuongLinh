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
int getLength(Node* head) {
    int count =0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current -> next;
    }
    return count;
}
int main() {
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    node1 -> next = node2;
    node2 -> prev = node1;
    node2 -> next = node3;

    node3 -> prev = node2;
    node3 -> next = node4;

    node4 -> prev = node3;
    node4 -> next = node5;

    node5 -> prev = node4;
    displayList(node1);
    printf("\nDanh sach lien ket co %d phan tu\n", getLength(node1));
}

