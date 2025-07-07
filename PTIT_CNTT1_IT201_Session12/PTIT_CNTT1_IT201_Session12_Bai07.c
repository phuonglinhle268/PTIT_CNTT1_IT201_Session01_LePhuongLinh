#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> data = data;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    return newNode;
}
Node* insertNode(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current -> next != NULL) {
        current = current -> next;
    }
    current -> next = newNode;
    newNode -> prev = current;
    return head;
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
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current -> next;
    }
    return count;
}
void sortList(Node* head) {
    int length = getLength(head);
    for (int i =0; i< length - 1; i++) {
        Node* current = head;
        while (current != NULL && current -> next != NULL) {
            if (current -> data > current -> next -> data) {
                int temp = current -> data;
                current -> data = current -> next -> data;
                current -> next -> data = temp;
            }
            current = current -> next;
        }
    }
}
int main() {
    int n, value;
    Node* head = NULL;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &value);
        head = insertNode(head, value);
    }
    displayList(head);
    sortList(head);
    printf("\nDanh sach moi: ");
    displayList(head);
    return 0;
}