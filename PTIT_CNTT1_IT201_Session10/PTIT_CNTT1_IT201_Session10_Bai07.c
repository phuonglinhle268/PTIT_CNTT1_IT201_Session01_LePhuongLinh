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
void sortList(Node* head) {
    Node *i, *j;
    for (i=head; i!=NULL; i=i->next) {
        for (j=i->next; j!=NULL; j=j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
int main() {
    Node* head = NULL;
    Node* node1 = createNode(5);
    Node* node2 = createNode(2);
    Node* node3 = createNode(4);
    Node* node4 = createNode(3);
    Node* node5 = createNode(1);

    head = node1;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;
    printf("Danh sach ban dau: ");
    displayList(head);
    sortList(head);
    printf("\nDanh sach sau sap xep: ");
    displayList(head);

}

