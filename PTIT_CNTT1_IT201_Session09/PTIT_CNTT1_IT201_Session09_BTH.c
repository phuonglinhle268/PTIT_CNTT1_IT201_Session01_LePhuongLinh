#include <stdio.h>
#include <stdlib.h>

//xay dung cau truc mot ptu trong lien ket don
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//xay dung ham khoi tao phan tu
Node* createNode(int data ) {
    //khoi tao node moi
    Node* node = (Node*)malloc(sizeof(Node));
    //gan gtri cho node moi
    node->data = data;     //<=>(*node).data = data;
    //gan con tro next cho node moi
    node->next = NULL;
    //tra ve gtri
    return node;
}

//xay dung ham hien thi danh sach lien ket
void displayList(Node* head) {
    Node* current = head;
    while (head != NULL) {
        printf("%d ->", current -> data);
        current = current -> head;
    }
}

//xay dung ham them vao cuoi
Node* insertAtEnd(Node* head) {
    //khoi tao ptu can duoc them moi
    Node* newNode = createNode(4);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //duyet den ptu cuoi cung
    Node* lastNode = head;
    while (lastNode -> next != NULL) {
        lastNode = lastNode -> next;
    }
    //cap nhat cac con tro can thiet
    lastNode -> next = newNode;
    //tra ve dsach lien ket don moi
    return head;
}

int main(void) {
    //khoi tao danh sach lien ket don
    Node* head = NULL;
    //khoi tao 3 node co gtri la 1,2,3
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    //dua 3 node vao danh sach
    head = node1;
    node1->next = node2;
    node2->next = node3;
    // tam tao ra dsach: head->1->2->3->NULL
    return 0;
}
