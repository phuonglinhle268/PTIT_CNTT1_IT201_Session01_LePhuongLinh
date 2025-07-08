#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *arr;
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
int isFull(Stack* stack) {
    if (stack -> top >= stack -> cap - 1) {
        return 1;
    }
    return 0;
}
int isEmpty(Stack* stack) {
    if (stack -> top == -1) {
        return 1;
    }
    return 0;
}
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day");
        return;
    }
    stack -> top++;
    stack -> arr[stack -> top] = value;

}
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong");
        return -1;
    }
    char value = stack -> arr[stack -> top];
    stack -> top--;
    return value;
}
int doixung(char str[]) {
    int len = strlen(str);
    Stack* stack = createStack(len);
    for (int i=0; i<len/2; i++) {
        push(stack, str[i]);
    }
    int string;
    if (len%2 == 0) {
        string = len/2;
    } else {
        string = len/2 + 1;
    }
    for (int i= string; i< len; i++) {
        char top = pop(stack);
        if (str[i] != top) {
            free(stack -> arr);
            free(stack);
            return 0;
        }
    }
    free(stack -> arr);
    free(stack);
    return 1;
}
int main() {
    char str[100];
    printf("Nhap chuoi: ");
    scanf("%s", str);
    if (doixung(str)) {
        printf("TRUE", str);
    } else {
        printf("FALSE", str);
    }
    return 0;
}

