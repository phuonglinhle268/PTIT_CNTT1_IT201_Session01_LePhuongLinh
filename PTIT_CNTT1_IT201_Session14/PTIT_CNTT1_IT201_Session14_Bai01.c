#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return NULL;
    }
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}
typedef struct Stack {
    Node* top;
}Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack -> top = NULL;
    return stack;
}
int main() {
    Stack* newStack = createStack();
    if (newStack != NULL) {
        printf("Khoi tao ngan xep thanh cong");
    } else {
        printf("Khoi tao khong thanh cong");
    }
    free(newStack);
}