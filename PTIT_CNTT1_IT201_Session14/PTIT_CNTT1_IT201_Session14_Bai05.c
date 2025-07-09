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
int pop(Stack* stack) {
    if (stack -> top == NULL) {
        printf("Ngan xep rong");
        return -1;
    }
    Node* temp = stack -> top;
    int value = temp -> data;
    stack -> top = temp -> next;
    free(temp);
    return value;
}
int firstElement(Stack* stack) {
    if (stack -> top == NULL) {
        printf("Ngan xep rong");
        return -1;
    }
    return stack -> top -> data;
}
void printStack(Stack* stack) {
    Node* current = stack -> top;

    printf("Cac phan tu trong ngan xep: ");
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
    if (newStack == NULL) {
        return 1;
    }

    push(newStack, 1);
    push(newStack, 2);
    push(newStack, 3);
    printStack(newStack);
    int check = firstElement(newStack);
    if (check != -1) {
        printf("Phan tu tren dau la: %d\n",check);
    }


    freeStack(newStack);
}


