#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int cap;
} Stack;

Stack* createStack(int cap) {
    Stack* stack =(Stack*)malloc(sizeof(Stack));
    stack -> arr = (int*)malloc(cap* sizeof(int));
    stack -> top = -1;
    stack -> cap = cap;
    return stack;
}

int main() {
    int n = 5;
    Stack* stack = createStack(n);
    if (stack != NULL && stack -> arr != NULL) {
        printf("Khoi tao thanh cong");
    } else {
        printf("Khoi tao khong thanh cong");
    }
    free(stack -> arr);
    free(stack);
}