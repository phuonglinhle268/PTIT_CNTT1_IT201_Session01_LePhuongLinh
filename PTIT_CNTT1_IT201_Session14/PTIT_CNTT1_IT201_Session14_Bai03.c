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
void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    if (newNode == NULL) {
        return;
    }
    newNode -> next = stack -> top;
    stack -> top = newNode;
}
void printStack(Stack* stack) {
    Node* current = stack -> top;

    printf("\nCac phan tu trong ngan xep: ");
    while (current != NULL) {
        printf("%d <-> ", current -> data);
        current = current -> next;
    }
    printf("NULL\n");
}
void freeStack(Stack* stack) {
    Node* current = stack -> top;
    while (current != NULL) {
        Node* temp = current;
        current = current -> next;
        free(temp);
    }
    free(stack);
}
int main() {
    Stack* newStack = createStack();

    push(newStack, 1);
    push(newStack, 2);
    push(newStack, 3);
    printStack(newStack);
    freeStack(newStack);
}
