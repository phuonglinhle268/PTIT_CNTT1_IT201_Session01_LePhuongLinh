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
Node* deleteNode(Node* head, int position) {
    if (position <0) {
        printf("Khong hop le");
        return head;
    }
    if (position == 0) {
        Node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }
    Node* current = head;
    int index = 0;
    while (current != NULL && index < position-1) {
        current = current -> next;
        index++;
    }
    Node* temp = current -> next;
    current -> next = temp -> next;
    free(temp);
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

    int position;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &position);
    printf("Danh sach moi: ");
    head = deleteNode(head, position);
    displayList(head);
}
