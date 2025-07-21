#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Operation {
    char action;
    char value;
} Operation;

typedef struct Stack {
    Operation* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (Operation*)malloc(sizeof(Operation) * capacity);
    return stack;
}

void push(Stack* stack, Operation op) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = op;
}

Operation pop(Stack* stack) {
    Operation empty = {' ', ' '};
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return empty;
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void display(Stack* undo) {
    printf("Van ban hien tai: ");
    for (int i = 0; i <= undo->top; i++) {
        if (undo->data[i].action == 'I') {
            printf("%c", undo->data[i].value);
        }
    }
    printf("\n");
}

int main() {
    Stack* undo = createStack(100);
    Stack* redo = createStack(100);
    int choice;

    do {
        printf("\n----- TEXT EDITOR -----\n");
        printf("1. INSERT x\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. HIEN THI\n");
        printf("5. THOAT\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                char x;
                printf("Nhap ky tu can them: ");
                scanf("%c", &x);
                Operation op = {'I', x};
                push(undo, op);
                redo->top = -1;
                break;
            }
            case 2: {
                if (!isEmpty(undo)) {
                    Operation op = pop(undo);
                    push(redo, op);
                    printf("Da undo ky tu: %c\n", op.value);
                } else {
                    printf("Khong co thao tac de undo.\n");
                }
                break;
            }
            case 3: {
                if (!isEmpty(redo)) {
                    Operation op = pop(redo);
                    push(undo, op);
                    printf("Da redo ky tu: %c\n", op.value);
                } else {
                    printf("Khong co thao tac de redo.\n");
                }
                break;
            }
            case 4:
                display(undo);
                break;
            case 5:
                printf("Exit\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 5);
    return 0;
}
