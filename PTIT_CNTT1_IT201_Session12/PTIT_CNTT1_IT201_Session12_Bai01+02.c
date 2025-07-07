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
    newNode -> prev = NULL;;
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
int main() {
    int n, value;
    Node* head = NULL;
    Node* end = NULL;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = end = newNode;
        } else {
            end -> next = newNode;
            newNode -> prev = end;
            end = newNode;
        }
    }
    displayList(head);
    return 0;
}
