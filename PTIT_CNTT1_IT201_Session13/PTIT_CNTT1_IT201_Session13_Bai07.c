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
int daungoac(char expr[]) {
    int len = strlen(expr);
    Stack* stack = createStack(len);
    for (int i=0; i<len; i++) {
        char ch = expr[i];
        if (ch =='(' || ch == '[' || ch == '{') {
            push(stack, ch);
        }else if (ch == ')'|| ch == '}' || ch == ']') {
            if (isEmpty(stack)) {
                free(stack -> arr);
                free(stack);
                return 0;
            }
            char top = pop(stack);
            if ((ch =='(' &&ch == ')')
                || (ch == '[' && ch == ']')
                || (ch == '{' && ch == '}')) {
                free(stack -> arr);
                free(stack);
                return 0;
                }
        }
    }
    int result;
    if (isEmpty(stack)) {
        result = 1;
    } else {
        result = 0;
    }
    free(stack -> arr);
    free(stack);
    return result;
}

int main() {
    char expr[100];
    printf("Nhap bieu thuc: ");
    scanf("%s", expr);
    if (daungoac(expr)) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    return 0;
}


