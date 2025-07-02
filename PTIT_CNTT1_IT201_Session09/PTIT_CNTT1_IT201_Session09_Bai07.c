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
Node* insertNode(Node* head, int value, int position) {
    if (position <0) {
        printf("Khong hop le");
        return head;
    }
    Node* newNode = createNode(value);
    if (position == 0) {
        newNode -> next = head;
        return newNode;
    }
    Node* current = head;
    int index = 0;
    while (current != NULL && index < position-1) {
        current = current -> next;
        index++;
    }
    if (current == NULL) {
        free(newNode);
        return head;
    }
    newNode -> next = current -> next;
    current -> next = newNode;
    return head;
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

    int value;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    int position;
    printf("Nhap vi tri: ");
    scanf("%d", &position);
    printf("Danh sach moi: ");
    displayList(insertNode(head, value, position));
}
