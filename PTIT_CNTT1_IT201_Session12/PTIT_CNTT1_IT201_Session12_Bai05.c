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
Node* deleteNode(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current -> data == value) {
            Node* temp = current;
            if (temp -> prev != NULL) {
                temp -> prev -> next = temp -> next;
            } else {
                head = temp -> next;
            }
            if (temp -> next != NULL) {
                temp -> next -> prev = temp -> prev;
            }
            current = temp -> next;
            free(temp);
        } else {
            current = current -> next;
        }
    }
    return head;
}
int main() {
    int n, value;
    Node* head = NULL;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        printf("Nhap phan tu thu %d: ", i+1);
        scanf("%d", &value);
        head = insertNode(head,value);
    }
    displayList(head);
    printf("Nhap gia tri muon xoa: ");
    scanf("%d", &value);
    head = deleteNode(head, value);
    printf("\nDanh sach moi: ", value);
    displayList(head);
    return 0;
}

